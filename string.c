/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:05 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 18:10:42 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static void	ft_wstrsub(char **str, int len)
{
	int		numlen;
	int		widthlen;
	char	*plab;

	if (len < 0 || len >= ft_strlen(*str))
		return ;
	numlen = 0;
	while ((*str)[numlen] && numlen <= len)
	{
		widthlen = 1;
		if (((unsigned char)(*str)[numlen] & 240) == 240)
			widthlen = 4;
		else if (((unsigned char)(*str)[numlen] & 224) == 224)
			widthlen = 3;
		else if (((unsigned char)(*str)[numlen] & 192) == 192)
			widthlen = 2;
		if (numlen + widthlen > len)
			break ;
		numlen += widthlen;
	}
	(*str)[numlen] = '\0';
	plab = ft_strdup(*str);
	free(*str);
	*str = plab;
}

static int	apply_flags(char *str, t_flags *f)
{
	int		ret;

	ft_wstrsub(&str, f->prec);
	if (f->minus == 1)
		charappend(&str, ' ', f->minwid);
	else if (f->zero == 1)
		charprepend(&str, '0', f->minwid);
	else
		charprepend(&str, ' ', f->minwid);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int			pr_string(va_list *args, t_flags *f)
{
	char	*str;
	char	*tmp;
	wchar_t	*wstr;

	if (f->lenmod == 3 || f->conv == 'S')
	{
		if (!(wstr = va_arg(*args, wchar_t*)))
			return (apply_flags(ft_strdup("(null)"), f));
		if (!(str = (char*)malloc(sizeof(*str))))
			return (0);
		str[0] = '\0';
		while (*wstr)
		{
			tmp = wchar_to_str(wstr[0]);
			strappend(&str, tmp);
			free(tmp);
			wstr++;
		}
	}
	else
	{
		str = va_arg(*args, char*);
		return (apply_flags(str ? ft_strdup(str) : ft_strdup("(null)"), f));
	}
	return (apply_flags(str, f));
}

int			pr_nonprint(va_list *args, t_flags *f)
{
	char	*str;
	int		i;

	str = va_arg(*args, char*);
	str = str ? ft_strdup(str) : ft_strdup("(null)");
	i = -1;
	while (str[++i])
	{
		if (str[i] < 32 || str[i] > 126)
			str[i] = '.';
	}
	return (apply_flags(str, f));
}
