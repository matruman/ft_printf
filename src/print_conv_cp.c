/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_cp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:44:46 by matruman          #+#    #+#             */
/*   Updated: 2019/11/11 14:45:34 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_conv_cp(t_format_list *format_list)
{
	char	*str;
	char	c;
	int		count;

	count = 0;
	if (format_list->conv == 'c')
		c = (char)va_arg(*(format_list->ap), int);
	else
		c = '%';
	str = ft_strnew(1);
	str[0] = c;
	if (format_list->flag.zero && format_list->flag.minus == 0)
		str = add_prefix(str, format_list->width - 1, '0');
	else if (format_list->flag.minus == 0)
		str = add_prefix(str, format_list->width - 1, ' ');
	else
		str = add_suffix(str, format_list->width - 1, ' ');
	if (c == 0 && format_list->flag.minus && (count = 1))
		ft_putchar(c);
	count += ft_putstrn(str, -1);
	if (c == 0 && format_list->flag.minus == 0 && ++count)
		ft_putchar(c);
	free(str);
	return (count);
}
