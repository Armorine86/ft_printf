/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:16:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/06/16 09:11:45 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	percent_width(t_info *info)
{
	if (info->width > 1)
	{
		info->total_length = info->total_length + (info->width - 1);
		if (info->flags[e_zero] == '1' && info->flags[e_minus] != '1')
			while (--info->width + 1 > 1)
				write(1, "0", 1);
		else
			while (--info->width + 1 > 1)
				write(1, " ", 1);
	}
}

void	ft_percent(t_info *info)
{
	if (MAC_OS)
	{
		if (info->flags[e_minus] == '1')
			write(1, "%", 1);
		percent_width(info);
		if (info->flags[e_minus] == '0')
			write(1, "%", 1);
		info->total_length++;
		info->format++;
	}
	else
	{
		write(1, "%", 1);
		info->total_length++;
		info->format++;
	}
}
