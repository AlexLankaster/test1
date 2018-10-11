/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:04 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 19:00:20 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static int	apply_flags(char *str, t_flags *f)
{
	int		bmp;
	int		fcn;

	fcn = 0;
	if (*str == '\0')
		fcn = 1;
	if (f->minus == 1)
		charappend(&str, ' ', f->minwid - fcn);
	else if (f->zero == 1)
		charprepend(&str, '0', f->minwid - fcn);
	else
		charprepend(&str, ' ', f->minwid - fcn);
	bmp = ft_strlen(str);
	if (f->minus == 1 && fcn == 1)
		write(1, "\0", 1);
	ft_putstr(str);
	if (f->minus == 0 && fcn == 1)
		write(1, "\0", 1);
	free(str);
	return (bmp + fcn);
}

int			pr_not_flag(t_flags *f)
{
	char	*arr;

	arr = (char*)malloc(sizeof(*arr) * 2);
	if (!arr)
		return (0);
	arr[0] = f->conv;
	arr[1] = '\0';
	return (apply_flags(arr, f));
}

int			pr_char(va_list *args, t_flags *f)
{
	char	*arr;

	if (f->lenmod == 3 || f->conv == 'C')
		arr = wchar_to_str(va_arg(*args, wchar_t));
	else
	{
		arr = (char*)malloc(sizeof(*arr) * 2);
		if (!arr)
			return (0);
		arr[0] = (char)va_arg(*args, int);
		arr[1] = '\0';
	}
	return (apply_flags(arr, f));
}
