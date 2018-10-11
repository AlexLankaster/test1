/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:05 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 18:42:34 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		pr_color_text(va_list *args)
{
	char	*arr;
	char	*number;
	int		retry;
	int		color;

	color = va_arg(*args, int);
	arr = ft_strdup("\e[38;2;");
	number = ft_itoa_base((color >> 16) & 255, 10);
	strappend(&arr, number);
	free(number);
	strappend(&arr, ";");
	number = ft_itoa_base((color >> 8) & 255, 10);
	strappend(&arr, number);
	free(number);
	strappend(&arr, ";");
	number = ft_itoa_base(color & 255, 10);
	strappend(&arr, number);
	free(number);
	strappend(&arr, "m");
	retry = ft_strlen(arr);
	ft_putstr(arr);
	free(arr);
	return (retry);
}

int		pr_color_bg(va_list *args)
{
	char	*arr;
	char	*number;
	int		retry;
	int		color;

	color = va_arg(*args, int);
	arr = ft_strdup("\e[48;2;");
	number = ft_itoa_base((color >> 16) & 255, 10);
	strappend(&arr, number);
	free(number);
	strappend(&arr, ";");
	number = ft_itoa_base((color >> 8) & 255, 10);
	strappend(&arr, number);
	free(number);
	strappend(&arr, ";");
	number = ft_itoa_base(color & 255, 10);
	strappend(&arr, number);
	free(number);
	strappend(&arr, "m");
	retry = ft_strlen(arr);
	ft_putstr(arr);
	free(arr);
	return (retry);
}

int		pr_color_reset(void)
{
	ft_putstr("\e[0m");
	return (4);
}
