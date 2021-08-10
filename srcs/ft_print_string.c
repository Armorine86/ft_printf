/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:48:47 by armorine          #+#    #+#             */
/*   Updated: 2021/06/10 20:42:13 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	string_width(t_info *info, int s_len)
{
	if (info->width > s_len)
	{
		while (info->width > s_len)
		{
			write (1, " ", 1);
			info->width--;
			info->total_length++;
		}
	}
}

void	solve_string(t_info *info, char *str, int s_len)
{
	if (info->flags[e_minus] == '1' && info->point != 1)
		ft_putstr(str);
	string_width(info, s_len);
	if (info->flags[e_minus] == '0' && info->point != 1)
	{
		string_width(info, s_len);
		ft_putstr(str);
	}
	info->total_length = info->total_length + s_len;
	info->format++;
	free(str);
}

void	ft_print_string(t_info *info)
{
	char	*arg;
	char	*tmp;
	int		s_len;

	arg = va_arg(info->args, char *);
	if (arg == NULL)
		arg = "(null)";
	if (info->precision == 0)
	{
		tmp = ft_strnew(ft_strlen(arg));
		ft_strcpy(tmp, arg);
	}
	else
	{
		if (!MAC_OS && (info->precision < 6 && info->precision >= 0
				&& ft_strcmp(arg, "(null)") == 0))
			info->precision = 0;
		tmp = ft_strnew(info->precision);
		ft_strlcpy(tmp, arg, info->precision + 1);
	}
	if (info->point != 1)
		s_len = ft_strlen(tmp);
	else
		s_len = 0;
	solve_string(info, tmp, s_len);
}
