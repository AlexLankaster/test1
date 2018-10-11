/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:04 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 18:05:18 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*dup;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (!(dup = (char*)malloc(sizeof(*dup) * (len + 1))))
		return (NULL);
	dup[len] = '\0';
	while (len--)
		dup[len] = str[len];
	return (dup);
}

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

char	*ft_strsub(char *str, int start, int len)
{
	int		slen;
	char	*sub;

	if ((slen = ft_strlen(str)) < start + len)
		len = slen - start;
	if (!str || !(sub = (char*)malloc(sizeof(*sub) * (len + 1))))
		return (NULL);
	sub[len] = '\0';
	while (len--)
		sub[len] = str[start + len];
	return (sub);
}
