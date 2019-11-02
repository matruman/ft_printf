/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:23:18 by matruman          #+#    #+#             */
/*   Updated: 2019/11/02 15:58:47 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			zero_format(t_format_list *format_list)
{
	format_list->conv = 0;
	format_list->position = 0;
	format_list->len = 0;
	format_list->width = 0;
	format_list->precision = 0;
}

t_format_list	*format_list_new(const char *format)
{
	t_format_list   *format_list;

	format_list = (t_format_list *)malloc(sizeof(t_format_list));
	if (!format_list)
		return (NULL);
	format_list->format = format;
	format_list->flags = ft_strnew(4);
	format_list->mod = ft_strnew(5);
	if (!format_list->flags || !format_list->mod)
		return (NULL);
	format_list->next = NULL;
	return (format_list);
}

t_format_list	*get_format_list(const char *format)
{
	t_format_list	*format_list_start;
	t_format_list   *format_list;
	int				i;
	int				skip;

	format_list_start = format_list_new(format);
	format_list = format_list_start;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			format_list->position = i;
			if ((skip = get_format(format, format_list)))
			{
				if((format_list->next = format_list_new(format)))
					format_list = format_list->next;
				else
					return (NULL);
				i += skip;
			}
		}
		i++;
	}
	return (format_list_start);
}
