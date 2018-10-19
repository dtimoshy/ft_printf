/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:31:12 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/17 15:31:16 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdint.h>
# include <limits.h>

typedef enum	e_length
{
	NONE, HH, H, L, LL, J, Z
}				t_length;

typedef struct	s_handler
{
	int			pad_right;
	int			pad_zero;
	int			force_sign;
	int			space_flag;
	int			hash;
	int			width;
	int			prec;
	t_length	length;
	char		sp;
}				t_handler;

int				ft_printf(const char *format, ...);
void			parse_length(const char **fmt, t_handler *handler);
void			parse_specifier(const char **fmt, t_handler *handler);
int				handle_d(t_handler *h, va_list args);
int				handle_u(t_handler *handler, va_list args);
int				handle_o(t_handler *handler, va_list args);
int				handle_x(t_handler *handler, va_list args);
int				handle_p(t_handler *handler, va_list args);
int				handle_bx(t_handler *handler, va_list args);
int				handle_other(t_handler *handler);
int				handle_char(t_handler *h, va_list args);
int				handle_string(t_handler *h, va_list args);
int				num_conversion(t_handler *h, va_list args);
int				char_conversion(t_handler *h, va_list args);
char			*get_wchar(wchar_t value);
char			*get_wstr(wchar_t *value, int prec);
char			*convert_base_d(size_t unsgnd, int base);
char			*convert_base_opux(size_t unsgnd, int base);
char			*convert_base_bx(size_t unsgnd, int base);
int				prec_check_print(int prec, size_t len, char **s, int mode);
size_t			get_numlen(size_t usigned_num, int base, int is_unsigned);

#endif
