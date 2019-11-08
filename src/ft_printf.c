/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:19:24 by matruman          #+#    #+#             */
/*   Updated: 2019/11/03 18:41:27 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag(struct s_flag  flag);
void	print_mod(struct s_mod  mod);

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format_list	*format_list;

	va_start(ap, format);
	format_list = get_format_list(format, &ap);
	print_format_list(format_list);
	
	return (0);
}	
