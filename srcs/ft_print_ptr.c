/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:59:43 by armorine          #+#    #+#             */
/*   Updated: 2021/06/11 10:30:25 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	solve_zero_ptr(t_info *info, unsigned long nbr, int len, int padding)
{
	if (info->width < len || padding == 0)
	{
		if (nbr == 0 && info->point != 2)
			padding = 1;
		write(1, "0x", 2);
		ptr_width(info, len, padding);
		if (info->point == 2)
			ft_putnchar('0', padding);
		if (nbr != 0)
			convert_to_hex(nbr, 'x');
	}
	if (info->width > len && padding != 0)
	{
		ptr_width(info, len, padding);
		write(1, "0x", 2);
		ft_putnchar('0', padding);
		if (nbr != 0)
			convert_to_hex(nbr, 'x');
	}
}

void	solve_ptr_no_min(t_info *info, unsigned long nbr, int len, int padding)
{
	if (info->flags[e_zero] == '1')
		solve_zero_ptr(info, nbr, len, padding);
	if (info->flags[e_zero] != '1')
	{
		if (nbr == 0 && info->point != 2)
			padding = 1;
		if (info->width > len)
			ptr_width(info, len, padding);
		write(1, "0x", 2);
		ft_putnchar('0', padding);
		if (nbr != 0)
			convert_to_hex(nbr, 'x');
	}
	info->total_length += padding;
}

void	solve_ptr_minus(t_info *info, unsigned long nbr, int len, int padding)
{
	write(1, "0x", 2);
	ft_putnchar('0', padding);
	if (nbr == 0 && info->point != 2)
		padding = 1;
	info->total_length += padding;
	if (info->point != 1 && nbr != 0)
		convert_to_hex(nbr, 'x');
	if (info->width > len && nbr != 0)
	{
		while (--info->width + 1 > (len + padding))
		{
			write(1, " ", 1);
			info->total_length++;
		}
	}
	if (nbr == 0)
		null_ptr_minus(info, nbr, len, padding);
}

void	ft_print_pointer(t_info *info)
{
	unsigned long long	arg;
	unsigned long long	nbr;
	int					len;
	int					padding;

	arg = va_arg(info->args, long long);
	nbr = arg;
	len = 2;
	while (nbr > 0)
	{
		len++;
		nbr /= 16;
	}
	padding = info->precision - len + 2;
	if (padding < 0)
		padding = 0;
	if (info->flags[e_minus] == '1')
		solve_ptr_minus(info, arg, len, padding);
	else
		solve_ptr_no_min(info, arg, len, padding);
	info->total_length = info->total_length + len;
	info->format++;
}
