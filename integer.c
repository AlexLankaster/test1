/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:05 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 18:10:35 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int			pr_decimal(char *str, t_flags *f)
{
	int		ret;

	if (f->num == 0 && f->prec == 0)
		strempty(&str);
	put_comma(&str, f->apos);
	charprepend(&str, '0', f->prec);
	if (f->zero == 1 && f->minus == 0 && f->prec < 0)
	{
		charprepend(&str, '0', f->minwid - 1);
		if (f->sign == 0 || (f->plus == 0 && f->space == 0 && f->sign == 1))
			charprepend(&str, '0', f->minwid);
	}
	if (f->sign == -1)
		strprepend(&str, "-");
	else if (f->plus == 1 && f->sign == 1)
		strprepend(&str, "+");
	else if (f->space == 1 && f->sign == 1)
		strprepend(&str, " ");
	if (f->minus == 1)
		charappend(&str, ' ', f->minwid);
	charprepend(&str, ' ', f->minwid);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			pr_quat(char *str, t_flags *f)
{
	int		ret;

	if (f->num == 0 && f->prec == 0)
		strempty(&str);
	charprepend(&str, '0', f->prec);
	if (f->zero == 1 && f->minus == 0 && f->prec < 0)
	{
		if (f->pound == 1 && f->num != 0)
			charprepend(&str, '0', f->minwid - 2);
		else
			charprepend(&str, '0', f->minwid);
	}
	if (f->pound == 1 && f->num != 0)
		strprepend(&str, "0q");
	if (f->minus == 1)
		charappend(&str, ' ', f->minwid);
	else
		charprepend(&str, ' ', f->minwid);
	if (f->conv >= 'A' && f->conv <= 'Z')
		ft_strtoupper(str);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			pr_octal(char *str, t_flags *f)
{
	int		ret;

	if (f->num == 0 && f->prec == 0)
		strempty(&str);
	charprepend(&str, '0', f->prec);
	if (f->zero == 1 && f->minus == 0 && f->prec < 0)
	{
		if (f->pound == 1 && f->num != 0)
			charprepend(&str, '0', f->minwid - 1);
		else
			charprepend(&str, '0', f->minwid);
	}
	if (f->pound == 1 && *str != '0')
		strprepend(&str, "0");
	if (f->minus == 1)
		charappend(&str, ' ', f->minwid);
	else
		charprepend(&str, ' ', f->minwid);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			pr_binary(char *str, t_flags *f)
{
	int		ret;

	if (f->num == 0 && f->prec == 0)
		strempty(&str);
	charprepend(&str, '0', f->prec);
	if (f->zero == 1 && f->minus == 0 && f->prec < 0)
	{
		if (f->pound == 1 && f->num != 0)
			charprepend(&str, '0', f->minwid - 2);
		else
			charprepend(&str, '0', f->minwid);
	}
	if (f->pound == 1 && f->num != 0)
		strprepend(&str, "0b");
	if (f->minus == 1)
		charappend(&str, ' ', f->minwid);
	else
		charprepend(&str, ' ', f->minwid);
	if (f->conv >= 'A' && f->conv <= 'Z')
		ft_strtoupper(str);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			pr_hex(char *str, t_flags *f, int fmt)
{
	int		ret;

	if (f->num == 0 && f->prec == 0)
		strempty(&str);
	charprepend(&str, '0', f->prec);
	if (f->zero == 1 && f->minus == 0 && f->prec < 0)
	{
		if ((f->pound == 1 && f->num != 0) || fmt == 1)
			charprepend(&str, '0', f->minwid - 2);
		else
			charprepend(&str, '0', f->minwid);
	}
	if ((f->pound == 1 && f->num != 0) || fmt == 1)
		strprepend(&str, "0x");
	if (f->minus == 1)
		charappend(&str, ' ', f->minwid);
	else
		charprepend(&str, ' ', f->minwid);
	if (f->conv >= 'A' && f->conv <= 'Z')
		ft_strtoupper(str);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}
