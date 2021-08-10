/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:33:45 by armorine          #+#    #+#             */
/*   Updated: 2021/06/15 10:10:31 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_input(t_info *info)
{
	int					format_type;
	static t_formatter	*format_functions[9] = {
	[e_string] = ft_print_string,
	[e_char] = ft_print_char,
	[e_decimal_di_int] = ft_print_di_int,
	[e_uns_int] = ft_unsigned_int,
	[e_hexadecimal] = ft_print_xX,
	[e_percent] = ft_percent,
	[e_pointer] = ft_print_pointer,
	[e_ncount] = ft_ncount,
	/*[e_float] = ft_print_float*/};

	info->format++;
	ft_check_flags(info);
	ft_check_width(info);
	ft_check_precision(info);
	format_type = ft_check_fspec(info);
	format_functions[format_type](info);
}

int	ft_printf(const char *format, ...)
{
	t_info	*info;
	int		len;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	va_start(info->args, format);
	info->format = format;
	while (*info->format != '\0')
	{
		while (*info->format != '%' && *info->format != '\0')
		{
			ft_putchar(*info->format);
			info->format++;
			info->total_length++;
		}
		if (*info->format == '%')
			ft_check_input(info);
	}		
	va_end(info->args);
	len = info->total_length;
	free(info);
	return (len);
}
