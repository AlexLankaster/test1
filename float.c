/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:05 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 18:57:35 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char		*round_float(char *arr, int pos)
{
	int		i;

	i = 0;
	while (arr[i] == '0')
		i++;
	if (pos < 1 || pos >= 12000)
		return (arr);
	if (i == pos - 1 && arr[pos - 1] == '5')
	{
		if ((arr[pos] - '0') % 2 == 0)
			return (arr);
		arr[pos]++;
	}
	else if (arr[pos - 1] >= '5')
		arr[pos]++;
	while (arr[pos] == '0' + 10)
	{
		arr[pos] = '0';
		pos++;
		arr[pos]++;
	}
	return (arr);
}

int			handle_nan(long double j, t_flags *f, int ret)
{
	char		*arr;

	if (j != j)
		arr = ft_strdup("nan");
	else if (j == 1.0 / 0.0 || j == -1.0 / 0.0)
		arr = ft_strdup("inf");
	else
		return (-1);
	(f->conv >= 'j' && f->conv <= 'Z') ? ft_strtoupper(arr) : 0;
	if (f->sign == -1 && j == j)
		strprepend(&arr, "-");
	else if (f->plus == 1 && j == j)
		strprepend(&arr, "+");
	else if (f->space == 1 && j == j)
		strprepend(&arr, " ");
	if (f->minus == 1)
		charappend(&arr, ' ', f->minwid);
	charprepend(&arr, ' ', f->minwid);
	ft_putstr(arr);
	ret = ft_strlen(arr);
	free(arr);
	return (ret);
}

static int	apply_flags(char *integer, char *lsd, t_flags *f, int ret)
{
	put_comma(&integer, f->apos);
	if (f->pound == 1 || ft_strlen(lsd) > 0)
		strappend(&integer, ".");
	strappend(&integer, lsd);
	free(lsd);
	if (f->zero == 1 && f->minus == 0)
	{
		charprepend(&integer, '0', f->minwid - 1);
		if (f->sign == 1 && f->plus == 0 && f->space == 0)
			charprepend(&integer, '0', f->minwid);
	}
	if (f->sign == -1)
		strprepend(&integer, "-");
	else if (f->plus == 1)
		strprepend(&integer, "+");
	else if (f->space == 1)
		strprepend(&integer, " ");
	if (f->minus == 1)
		charappend(&integer, ' ', f->minwid);
	charprepend(&integer, ' ', f->minwid);
	ret = ft_strlen(integer);
	ft_putstr(integer);
	free(integer);
	return (ret);
}

int			pr_float(va_list *args, t_flags *f)
{
	long double	j;
	char		*arr;
	char		*lsd;
	char		*integer;
	int			i;

	if (f->lenmod == 7)
		j = va_arg(*args, long double);
	else
		j = va_arg(*args, double);
	f->sign = j < 0 ? -1 : 1;
	if ((i = handle_nan(j, f, 0)) >= 0)
		return (i);
	if (f->prec < 0)
		f->prec = 6;
	arr = round_float(make_float(j), 6000 - f->prec);
	lsd = ft_strsub(arr, 6000 - f->prec, f->prec);
	ft_strrev(lsd);
	i = 11999;
	while (arr[i] == '0' && i >= 5999)
		i--;
	integer = ft_strsub(arr, 6000, (i - 5999) <= 0 ? 1 : (i - 5999));
	ft_strrev(integer);
	free(arr);
	return (apply_flags(integer, lsd, f, 0));
}
