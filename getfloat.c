/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfloat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:04 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 18:10:36 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char	*get_pow(int base, int exp)
{
	char	*str;
	int		i;
	int		len;
	int		trans;

	if (!(str = (char*)malloc(sizeof(*str) * (exp + 2))))
		return (NULL);
	i = 0;
	str[0] = '1';
	len = 1;
	while (++i < exp + 2)
		str[i] = '0';
	while (exp-- && (trans = 1))
	{
		i = -1;
		while ((trans /= 10) >= 0 && ++i < len)
		{
			trans += (str[i] - '0') * base;
			str[i] = trans % 10 + '0';
		}
		if ((str[len] = trans + '0') != '0')
			len++;
	}
	str[len] = '\0';
	return (str);
}

static void	add_num(char *dst, char *src)
{
	int		trans;
	int		i;

	if (!dst || !src)
		return ;
	trans = 0;
	i = 0;
	while (src[i])
	{
		trans += *dst + src[i] - '0' * 2;
		*dst = trans % 10 + '0';
		trans /= 10;
		dst++;
		i++;
	}
	while (trans)
	{
		trans += *dst - '0';
		*dst = trans % 10 + '0';
		trans /= 10;
		dst++;
	}
	free(src);
}

static void	float_arr_fill(char *str, unsigned long *frac, int exp)
{
	unsigned long	bit;

	bit = 1UL << 63;
	while (bit)
	{
		if (!(*frac & bit))
		{
			exp--;
			bit >>= 1;
			continue ;
		}
		if (exp >= 0)
			add_num(str + 6000, get_pow(2, exp));
		else
			add_num(str + 6000 + exp, get_pow(5, -exp));
		exp--;
		bit >>= 1;
	}
}

char		*make_float(long double a)
{
	unsigned long	*frac;
	int				i;
	int				exp;
	char			*str;

	if (!(str = (char*)malloc(sizeof(*str) * 12001)))
		return (NULL);
	i = -1;
	while (++i < 12000)
		str[i] = '0';
	str[12000] = '\0';
	frac = (unsigned long*)&a;
	exp = (frac[1] & ((1 << 15) - 1)) - (1 << 14) + 1;
	float_arr_fill(str, frac, exp);
	return (str);
}
