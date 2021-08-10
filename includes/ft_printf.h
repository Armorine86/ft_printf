/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:50:11 by armorine          #+#    #+#             */
/*   Updated: 2021/06/15 10:33:59 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

# if __APPLE__
#  define MAC_OS 1
# else
#  define MAC_OS 0
# endif

enum	e_flags
{
	e_minus,
	e_zero,
};

typedef struct s_info
{
	const char	*format;
	va_list		args;
	char		flags[2];
	int			width;
	int			precision;
	int			total_length;
	int			point;
}					t_info;

typedef void	t_formatter(t_info *info);

enum	e_formats
{
	e_string,
	e_char,
	e_decimal_di_int,
	e_uns_int,
	e_hexadecimal,
	e_percent,
	e_pointer,
	e_ncount,
	//e_float
};

int		ft_printf(const char *format, ...);
int		ft_check_fspec(t_info *info);
void	ft_print_string(t_info *info);
void	ft_print_char(t_info *info);
//void	ft_print_float(t_info *info);
void	char_width(t_info *info);
void	ft_print_di_int(t_info *info);
void	solve_int_minus(t_info *info, int num, int len, int padding);
void	solve_int_no_minus(t_info *info, int num, int len, int padding);
void	solve_int_width(t_info *info, int num, int len, int padding);
void	solve_int_no_zero(t_info *info, int num, int len, int padding);
void	solve_uint_no_zero(t_info *info, long long nbr, int len, int padding);
void	solve_uint_width(t_info *info, long long nbr, int len, int padding);
void	solve_uint_flags(t_info *info, long long nbr, int len, int padding);
void	solve_ptr_no_min(t_info *info, unsigned long nbr, int len, int padding);
void	solve_ptr_minus(t_info *info, unsigned long nbr, int len, int padding);
void	solve_zero_ptr(t_info *info, unsigned long nbr, int len, int padding);
void	null_ptr_minus(t_info *info, unsigned int nbr, int len, int padding);
void	null_ptr_zero(t_info *info, unsigned int nbr, int len, int padding);
void	ptr_width_zero(t_info *info, int len, int padding);
void	ptr_width(t_info *info, int len, int padding);
void	ft_unsigned_int(t_info *info);
void	convert_to_hex(unsigned long long nbr, char format);
void	ft_ncount(t_info *info);
void	ft_print_xX(t_info *info);
void	ft_percent(t_info *info);
void	ft_print_pointer(t_info *info);
void	ft_check_flags(t_info *info);
void	ft_check_precision(t_info *info);
void	ft_check_width(t_info *info);

#endif