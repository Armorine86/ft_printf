/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:39:56 by mmondell          #+#    #+#             */
/*   Updated: 2021/06/15 10:43:02 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_float(t_info *info)
{
	long double	nbr;
	
	nbr = va_arg(info->args, long double);
	
	nbr = 0;
	info->format++;
}