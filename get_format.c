/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:25:05 by matruman          #+#    #+#             */
/*   Updated: 2019/11/02 16:17:56 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flags(const char *format, t_format_list *format_list)
{
	int     i;

	i = format_list->position + 1;
	while (isflag(format[i]))
	{
		if (format[i] == '#')
			(format_list->flags)[0] = '#';
		if (format[i] == '0')
			(format_list->flags)[1] = '0';
		if (format[i] == '+')
			(format_list->flags)[2] = '+';
		if (format[i] == '-')
			(format_list->flags)[3] = '-';
		i++;
	}
	return (i);
}

int		get_width(int start, const char *format, t_format_list *format_list)
{
	format_list->width = ft_atoi(format + start);
	while (ft_isdigit(format[start]))
		start++;
	return (start);
}

int		get_precision(int start, const char *format, t_format_list *format_list)
{
	if (format[start] == '.')
	{
		start++;
		format_list->precision = ft_atoi(format + start);
		while (ft_isdigit(format[start]))
			start++;
	}
	return (start);
}

int		get_mod(int start, const char *format, t_format_list *format_list)
{
	while (ismod(format[start]))
	{
		if (format[start] == 'h')
		{
			(format_list->mod)[0] = 'h';
			if (format[start + 1] == 'h')
				(format_list->mod)[1] = 'h';
		}
		if (format[start] == 'l')
		{
			(format_list->mod)[2] = 'l';
			if (format[start + 1] == 'l')
				(format_list->mod)[3] = 'l';
		}
		if (format[start] == 'L')
			(format_list->mod)[4] = 'L';
		start++;
	}
	return (start);
}
		

int		get_conv(int start, const char *format, t_format_list *format_list)
{
	if (isconv(format[start]))
	{
		format_list->conv = format[start];
		return (1);
	}
	return (0);
}

int				get_format(const char *format, t_format_list *format_list)
{
	int		start;

	if (format[format_list->position + 1] == '%')
	{
		format_list->conv = '%';
		return (1);
	}
	start = get_flags(format, format_list);
	start = get_width(start, format, format_list);
	start = get_precision(start, format, format_list);
	start = get_mod(start, format, format_list);
	if (get_conv(start, format, format_list))
	{
		format_list->len = start - format_list->position;
		return (format_list->len);
	}
	else
		return (0);
}
