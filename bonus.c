/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:04 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/09 18:22:11 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "ft_printf.h"

int		save_char_num(va_list *args, t_flags *f)
{
	int		*location;

	location = va_arg(*args, int*);
	if (f->lenmod == 1)
		*(signed char*)location = f->num_char;
	else if (f->lenmod == 2)
		*(short*)location = f->num_char;
	else if (f->lenmod == 3)
		*(long*)location = f->num_char;
	else if (f->lenmod == 4)
		*(long long*)location = f->num_char;
	else if (f->lenmod == 5)
		*(intmax_t*)location = f->num_char;
	else if (f->lenmod == 6)
		*(ssize_t*)location = f->num_char;
	else if (f->lenmod == 8)
		*(ptrdiff_t*)location = f->num_char;
	else
		*location = f->num_char;
	return (0);
}
