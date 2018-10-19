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
# include <stdbool.h>
# include "../libft/libft.h"
# include <stdint.h>
# include <limits.h>

typedef enum	e_length
{
	NONE, HH, H, L, LL, J, Z
}				t_length;

typedef struct	s_handler
{
	bool		pad_right;
	bool		pad_zero;
	bool		force_sign;
	bool		space_flag;
	bool		hash;
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
int				handle_dper(t_handler *handler, va_list args);
int				print_char(t_handler *h, va_list args);
int				print_string(t_handler *h, va_list args);
int				print_value(t_handler *h, char *result,
							size_t len, bool neg_sign);
int				num_conversion(t_handler *h, va_list args);
int				char_conversion(t_handler *h, va_list args);
char			*get_wchar(wchar_t value);
char			*convert_base_d(size_t unsgnd, int base);
char			*convert_base_opux(size_t unsgnd, int base);
char			*convert_base_bx(size_t unsgnd, int base);
bool			check_precision(int prec, char **result);
size_t			get_numlen(size_t usigned_num, int base, bool is_unsigned);
char			*printf_strjoin(char *s1, char *s2);

#endif
