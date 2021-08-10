/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 08:15:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/06/15 10:36:19 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_ncount(t_info *info)
{
	int	*n;
	
	n = va_arg(info->args, int *);
	*n = info->total_length;
	info->format++;
}