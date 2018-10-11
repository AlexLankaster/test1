/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:04 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 18:38:30 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static int	pr_conversion_p2(char **pos, va_list *args, t_flags *f)
{
	if ((*pos)[-1] == 'e' || (*pos)[-1] == 'E')
		return (pr_float_e(args, f));
	if ((*pos)[-1] == 'g' || (*pos)[-1] == 'G')
		return (pr_float_g(args, f));
	if ((*pos)[-1] == 'a' || (*pos)[-1] == 'A')
		return (pr_float_hex(args, f));
	if ((*pos)[-1] == 'n')
		return (save_char_num(args, f));
	if ((*pos)[-1] == 'b' || (*pos)[-1] == 'B')
		return (pr_binary(make_unsigned_int(args, f, 2), f));
	if ((*pos)[-1] == 'q' || (*pos)[-1] == 'Q')
		return (pr_quat(make_unsigned_int(args, f, 4), f));
	if ((*pos)[-1] == 'r')
		return (pr_nonprint(args, f));
	if ((*pos)[-1] == 'v')
		return (pr_color_text(args));
	if ((*pos)[-1] == 'w')
		return (pr_color_bg(args));
	if ((*pos)[-1] == 'y')
		return (pr_color_reset());
	if ((*pos)[-1] != '\0')
		return (pr_not_flag(f));
	(*pos)--;
	return (0);
}

static int	pr_conversion(char **pos, va_list *args, t_flags *f)
{
	make_arg(pos, args, f);
	make_flags(pos, f);
	make_minwid(pos, args, f);
	make_prec(pos, args, f);
	make_lenmod(pos, f);
	f->conv = (*pos)[0];
	(*pos)++;
	if ((*pos)[-1] == 'd' || (*pos)[-1] == 'i' || (*pos)[-1] == 'D')
		return (pr_decimal(make_int(args, f, 10), f));
	if ((*pos)[-1] == 'u' || (*pos)[-1] == 'U')
		return (pr_decimal(make_unsigned_int(args, f, 10), f));
	if ((*pos)[-1] == 'o' || (*pos)[-1] == 'O')
		return (pr_octal(make_unsigned_int(args, f, 8), f));
	if ((*pos)[-1] == 'x' || (*pos)[-1] == 'X')
		return (pr_hex(make_unsigned_int(args, f, 16), f, 0));
	if ((*pos)[-1] == 'p')
		return (pr_hex(make_unsigned_int(args, f, 16), f, 1));
	if ((*pos)[-1] == 's' || (*pos)[-1] == 'S')
		return (pr_string(args, f));
	if ((*pos)[-1] == 'c' || (*pos)[-1] == 'C')
		return (pr_char(args, f));
	if ((*pos)[-1] == 'f' || (*pos)[-1] == 'F')
		return (pr_float(args, f));
	return (pr_conversion_p2(pos, args, f));
}

int			ft_printf(const char *format, ...)
{
	char	*pos;
	va_list	args;
	t_flags	f;

	f.num_char = 0;
	pos = (char*)format;
	va_start(args, format);
	va_copy(f.arg_start, args);
	while (*pos)
	{
		if (*pos != '%')
		{
			write(1, pos, 1);
			f.num_char++;
			pos++;
		}
		else
		{
			pos++;
			f.num_char += pr_conversion(&pos, &args, &f);
		}
	}
	va_end(args);
	return (f.num_char);
}
