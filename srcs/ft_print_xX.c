/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:57:52 by armorine          #+#    #+#             */
/*   Updated: 2021/06/11 11:28:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_to_hex(unsigned long long nbr, char format)
{
	if (nbr >= 16)
	{
		convert_to_hex(nbr / 16, format);
		convert_to_hex(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
		{
			if (format == 'x')
				ft_putchar(nbr - 10 + 'a');
			else if (format == 'X')
				ft_putchar(nbr - 10 + 'A');
		}
	}
}

void	solve_hex_no_minus(t_info *info, long long nbr, int len, int padding)
{
	if (info->width > len && (info->flags[e_zero] != '1' || info->point != 0))
	{
		while (--info->width + 1 > (len + padding))
		{
			write(1, " ", 1);
			info->total_length++;
		}
	}
	if (info->width > len && info->flags[e_zero] == '1' && info->point == 0)
	{
		while (--info->width + 1 > (len + padding))
		{
			write(1, "0", 1);
			info->total_length++;
		}
	}
	ft_putnchar('0', padding);
	info->total_length += padding;
	if (info->point != 1 || nbr != 0)
		convert_to_hex(nbr, *info->format);
}

void	solve_hex_minus(t_info *info, long long nbr, int len, int padding)
{
	ft_putnchar('0', padding);
	info->total_length += padding;
	if (info->point != 1 || nbr != 0)
		convert_to_hex(nbr, *info->format);
	if (info->width > len)
	{
		while (--info->width + 1 > (len + padding))
		{
			write(1, " ", 1);
			info->total_length++;
		}
	}
}

void	ft_print_xX(t_info *info)
{
	unsigned long long	arg;
	long long			nbr;
	int					len;
	int					padding;

	arg = (unsigned int) va_arg(info->args, unsigned long long);
	nbr = arg;
	len = 0;
	if (arg == 0 && info->point != 1)
		len++;
	while (nbr > 0)
	{
		len++;
		nbr = nbr / 16;
	}
	padding = info->precision - len;
	if (padding < 0)
		padding = 0;
	if (info->flags[e_minus] == '1')
		solve_hex_minus(info, arg, len, padding);
	else
		solve_hex_no_minus(info, arg, len, padding);
	info->total_length = info->total_length + len;
	info->format++;
}
