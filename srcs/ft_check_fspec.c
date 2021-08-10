/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fspec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:01:16 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/05 09:02:45 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_fspec2(t_info *info)
{
	int	type;

	type = 0;
	if (*info->format == 'p')
		type = e_pointer;
	else if (*info->format == 'n')
		type = e_ncount;
	//else if (*info->format == 'f')
	//	type = e_float;
	else
		ft_putstr("ERROR");
	return (type);
}

int	ft_check_fspec(t_info *info)
{
	int	type;

	type = 0;
	if (*info->format == 's')
		type = e_string;
	else if (*info->format == 'c')
		type = e_char;
	else if (*info->format == 'd')
		type = e_decimal_di_int;
	else if (*info->format == 'i')
		type = e_decimal_di_int;
	else if (*info->format == 'u')
		type = e_uns_int;
	else if (*info->format == 'x')
		type = e_hexadecimal;
	else if (*info->format == 'X')
		type = e_hexadecimal;
	else if (*info->format == '%')
		type = e_percent;
	else
		type = ft_check_fspec2(info);
	return (type);
}
