/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:05 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 18:10:42 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*wchar_to_str(wchar_t c)
{
	int		len;
	char	*str;
	int		i;

	if (c < 0x100)
		len = 1;
	else if (c < 0x800)
		len = 2;
	else if (c < 0x10000)
		len = 3;
	else if (c < 0x110000)
		len = 4;
	else
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[0] = (char)c;
	if (len == 1)
		return (str);
	i = -1;
	while (++i < len)
		str[i] = (1 << 7) | ((c >> (6 * (len - i - 1))) & ((1 << 6) - 1));
	str[0] |= (1 << 7) - (1 << (8 - len));
	return (str);
}
