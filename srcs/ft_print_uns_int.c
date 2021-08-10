/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:47:03 by mmondell          #+#    #+#             */
/*   Updated: 2021/06/11 10:38:22 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	solve_uint_no_zero(t_info *info, long long nbr, int len, int padding)
{
	if (info->point != 1 || nbr != 0)
	{
		while (--info->width + 1 > len + padding)
		{
			write(1, " ", 1);
			info->total_length++;
		}
	}
	else
	{
		while (--info->width + 1 > len + padding)
		{
			write(1, " ", 1);
			info->total_length++;
		}
	}
}

void	solve_uint_width(t_info *info, long long nbr, int len, int padding)
{
	if (info->flags[e_zero] == '1' && (info->flags[e_minus] != 1
			&& padding == 0))
	{
		if (info->point != 0 || info->flags[e_minus] == '1')
		{
			while (--info->width + 1 > len)
			{
				write(1, " ", 1);
				info->total_length++;
			}
		}
		else
		{
			while (--info->width + 1 > len)
			{
				write(1, "0", 1);
				info->total_length++;
			}
		}
	}
	else
		solve_uint_no_zero(info, nbr, len, padding);
}

void	solve_uint_flags(t_info *info, long long nbr, int len, int padding)
{
	if (info->flags[e_minus] == '1' && (info->point != 1 || nbr != 0))
	{
		ft_putnchar('0', padding);
		info->total_length += padding;
		ft_putunsnbr(nbr);
	}
	if (info->width > len)
		solve_uint_width(info, nbr, len, padding);
	if (info->flags[e_minus] != '1' && (info->point != 1 || nbr != 0))
	{
		ft_putnchar('0', padding);
		info->total_length += padding;
		ft_putunsnbr(nbr);
	}
}

void	ft_unsigned_int(t_info *info)
{
	unsigned long long	arg;
	long long			nbr;
	int					len;
	int					padding;

	arg = (unsigned int)va_arg(info->args, long long);
	nbr = arg;
	len = 0;
	if (arg == 0 && info->point != 1)
		len++;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	padding = info->precision - len;
	if (padding < 0)
		padding = 0;
	solve_uint_flags(info, arg, len, padding);
	info->total_length = info->total_length + len;
	info->format++;
}
