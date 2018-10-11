/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:05 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 18:59:05 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	apply_flags(char *lsd, char *bmp, char *exp, t_flags *f)
{
	(f->pound == 1 || ft_strlen(bmp) > 0) ? strappend(&lsd, ".") : 0;
	strappend(&lsd, bmp);
	free(bmp);
	(f->conv == 'E') ? strappend(&lsd, "E") : strappend(&lsd, "e");
	(f->prec == -1) ? strappend(&lsd, "-") : strappend(&lsd, "+");
	charprepend(&exp, '0', 2);
	strappend(&lsd, exp);
	free(exp);
	if (f->zero == 1 && f->minus == 0)
		charprepend(&lsd, '0', f->minwid - 1);
	if (f->zero && !(f->minus) && f->sign == 1 && !(f->plus) && !(f->space))
		charprepend(&lsd, '0', f->minwid);
	if (f->sign == -1)
		strprepend(&lsd, "-");
	else if (f->plus == 1)
		strprepend(&lsd, "+");
	else if (f->space == 1)
		strprepend(&lsd, " ");
	if (f->minus == 1)
		charappend(&lsd, ' ', f->minwid);
	charprepend(&lsd, ' ', f->minwid);
	f->prec = ft_strlen(lsd);
	ft_putstr(lsd);
	free(lsd);
	return (f->prec);
}

int			pr_float_e(va_list *args, t_flags *f)
{
	long double	a;
	char		*str;
	char		*bmp;
	char		*lsd;
	int			i;

	(f->lenmod != 7) ? (a = va_arg(*args, double)) : 0;
	if (f->lenmod == 7)
		a = va_arg(*args, long double);
	f->sign = a < 0 ? -1 : 1;
	if ((i = handle_nan(a, f, 0)) >= 0)
		return (i);
	f->prec = (f->prec < 0) ? 6 : f->prec;
	str = make_float(a);
	i = 11999;
	while (str[i] == '0' && i >= 0)
		i--;
	i = i == -1 ? 6000 : i;
	str = round_float(str, i - f->prec);
	lsd = ft_strsub(str, i, 1);
	bmp = ft_strsub(str, i - f->prec, f->prec);
	ft_strrev(bmp);
	free(str);
	f->prec = (i < 6000) ? -1 : 1;
	return (apply_flags(lsd, bmp, ft_itoa_base((i - 6000) * f->prec, 10), f));
}
