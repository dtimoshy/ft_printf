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

# define NO 0
# define HH 1
# define H 2
# define L 3
# define LL 4
# define J 5
# define Z 6

typedef struct	s_pf
{
	short		right;
	short		zero;
	short		sign;
	short		space;
	short		hash;
	short		length;
	int			width;
	int			prec;
	char		spec;
}				t_pf;

int				ft_printf(const char *format, ...);
void			len_parse(const char **fmt, t_pf *pf);
void			spec_parse(const char **fmt, t_pf *pf);
int				handle_d(t_pf *pf, va_list args);
int				handle_u(t_pf *pf, va_list args);
int				handle_o(t_pf *pf, va_list args);
int				handle_x(t_pf *pf, va_list args);
int				handle_p(t_pf *pf, va_list args);
int				handle_bx(t_pf *pf, va_list args);
int				handle_other(t_pf *pf);
int				handle_char(t_pf *pf, va_list args);
int				handle_string(t_pf *pf, va_list args);
int				num_convert(t_pf *pf, va_list args);
int				char_convert(t_pf *pf, va_list args);
char			*wchar_get(wchar_t value);
char			*wstr_get(wchar_t *value, int prec);
char			*convert_base_d(size_t unsgnd, int base);
char			*convert_base_opux(size_t unsgnd, int base);
char			*convert_base_bx(size_t unsgnd, int base);
int				prec_check_print(int prec, size_t len, char **s, int mode);

#endif
