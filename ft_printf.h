/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:48:04 by akurpas           #+#    #+#             */
/*   Updated: 2018/10/10 19:00:21 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>


typedef struct	s_flags
{
	uintmax_t	num;
	int			pound;
	int			zero;
	int			minus;
	int			plus;
	int			minwid;
	int			prec;
	int			lenmod;	
	int			space;
	int			apos;
	int			sign;
	char		conv;
	va_list		arg_start;
	int			num_char;
}				t_flags;
int				ft_printf(const char *format, ...);
int				pr_float(va_list *args, t_flags *f);
int				pr_float_e(va_list *args, t_flags *f);
int				pr_float_g(va_list *args, t_flags *f);
int				pr_float_hex(va_list *args, t_flags *f);
void			make_arg(char **pos, va_list *args, t_flags *f);
void			make_flags(char **pos, t_flags *f);
void			make_minwid(char **pos, va_list *args, t_flags *f);
void			make_prec(char **pos, va_list *args, t_flags *f);
void			make_lenmod(char **pos, t_flags *f);
char			*ft_itoa_base(uintmax_t n, int base);
void			charprepend(char **str, char c, int min_len);
void			charappend(char **str, char c, int min_len);
void			strprepend(char **dst, char *src);
void			strappend(char **dst, char *src);
void			put_comma(char **str, int i);
int				ft_strlen(char *str);
char			*ft_strdup(char *str);
void			ft_putstr(char *str);
int				handle_nan(long double a, t_flags *f, int ret);
int				pr_color_text(va_list *args);
int				pr_color_bg(va_list *args);
int				pr_color_reset(void);
char			*ft_strsub(char *str, int start, int len);
void			ft_strtoupper(char *str);
void			ft_strrev(char *str);
void			strempty(char **str);
char			*wchar_to_str(wchar_t c);
char			*make_int(va_list *args, t_flags *f, int base);
char			*make_unsigned_int(va_list *args, t_flags *f, int base);
char			*make_float(long double a);
int				pr_decimal(char *str, t_flags *f);
int				pr_hex(char *str, t_flags *f, int fmt);
int				pr_octal(char *str, t_flags *f);
int				pr_binary(char *str, t_flags *f);
int				pr_quat(char *str, t_flags *f);
int				pr_string(va_list *args, t_flags *f);
int				pr_nonprint(va_list *args, t_flags *f);
int				pr_char(va_list *args, t_flags *f);
int				pr_not_flag(t_flags *f);
int				save_char_num(va_list *args, t_flags *f);
char			*round_float(char *arr, int pos);

#endif
