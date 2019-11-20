/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:30:44 by matruman          #+#    #+#             */
/*   Updated: 2019/11/03 20:54:54 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_format(t_format_list *format_list)
{
	int		count;
	
	count = 0;
	if (format_list->conv == 'd' || format_list->conv == 'i')
		count = print_conv_di(format_list);
	else if (format_list->conv == 'o' || format_list->conv == 'u'
		|| format_list->conv == 'x' || format_list->conv == 'X'
		|| format_list->conv == 'p')
		count = print_conv_pouxx(format_list);
	else if (format_list->conv == 'c' || format_list->conv == '%')
		count = print_conv_cp(format_list);
	else if (format_list->conv == 's')
		count = print_conv_s(format_list);
	else if (format_list->conv == 'f')
		count = print_conv_float(format_list);
	return (count);
}

int		print_format_list(t_format_list *format_list)
{
	int		start;
	int		scount;
	int		fcount;
	int		fcount_tmp;

	start = 0;
	scount = 0;
	fcount = 0;
	while (format_list && format_list->conv)
	{
		scount += ft_putstrn(format_list->format + start,
			format_list->position - start);
		fcount_tmp = print_format(format_list);
		start = format_list->position + format_list->len;
		fcount += fcount_tmp;
		format_list = format_list->next;
	}
	scount += ft_putstrn(format_list->format + start, -1);
	return (scount + fcount);
}
