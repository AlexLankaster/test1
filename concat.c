/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:04 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 18:46:14 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	charprepend(char **str, char c, int min_len)
{
	int		lenght;
	char	*new_ch;

	if (!str || !*str)
		return ;
	lenght = ft_strlen(*str);
	if (min_len <= lenght)
		return ;
	if (!(new_ch = (char*)malloc(sizeof(*new_ch) * (min_len) + 1)))
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new_ch[min_len] = '\0';
	while (lenght--)
		new_ch[--min_len] = (*str)[lenght];
	while (min_len--)
		new_ch[min_len] = c;
	free(*str);
	*str = new_ch;
}

void	charappend(char **str, char c, int min_len)
{
	int		lenght;
	char	*new_ch;

	if (!str || !*str)
		return ;
	lenght = ft_strlen(*str);
	if (min_len <= lenght)
		return ;
	if (!(new_ch = (char*)malloc(sizeof(*new_ch) * (min_len) + 1)))
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new_ch[min_len] = '\0';
	while (min_len > lenght)
		new_ch[--min_len] = c;
	while (min_len--)
		new_ch[min_len] = (*str)[min_len];
	free(*str);
	*str = new_ch;
}

void	strprepend(char **dst, char *src)
{
	int		lenght_dest;
	int		lenght_src;
	char	*cat;

	if (!dst || !*dst || !src)
		return ;
	lenght_dest = ft_strlen(*dst);
	lenght_src = ft_strlen(src);
	if (!(cat = (char*)malloc(sizeof(*cat) * (lenght_dest + lenght_src + 1))))
	{
		free(*dst);
		*dst = NULL;
		return ;
	}
	cat[lenght_dest + lenght_src] = '\0';
	while (lenght_dest--)
		cat[lenght_dest + lenght_src] = (*dst)[lenght_dest];
	while (lenght_src--)
		cat[lenght_src] = src[lenght_src];
	free(*dst);
	*dst = cat;
}

void	strappend(char **dst, char *src)
{
	int		lenght_dest;
	int		lenght_src;
	char	*cat;

	if (!dst || !*dst || !src)
		return ;
	lenght_dest = ft_strlen(*dst);
	lenght_src = ft_strlen(src);
	if (!(cat = (char*)malloc(sizeof(*cat) * (lenght_dest + lenght_src + 1))))
	{
		free(*dst);
		*dst = NULL;
		return ;
	}
	cat[lenght_dest + lenght_src] = '\0';
	while (lenght_src--)
		cat[lenght_dest + lenght_src] = src[lenght_src];
	while (lenght_dest--)
		cat[lenght_dest] = (*dst)[lenght_dest];
	free(*dst);
	*dst = cat;
}

void	put_comma(char **str, int i)
{
	int		ind;
	int		count;
	char	*new_ch;

	if (!i || !str || !*str)
		return ;
	ind = ft_strlen(*str) - 1;
	i = ind + ind / 3 + 1;
	if (!(new_ch = (char*)malloc(sizeof(*new_ch) * (i + 1))))
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new_ch[i] = '\0';
	count = -1;
	while (i-- && ++count >= 0)
	{
		if (count % 4 == 3)
			new_ch[i] = ',';
		else
			new_ch[i] = (*str)[ind--];
	}
	free(*str);
	*str = new_ch;
}
