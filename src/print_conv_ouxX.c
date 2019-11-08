/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_ouxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:33:00 by matruman          #+#    #+#             */
/*   Updated: 2019/11/08 19:34:18 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *get_str(t_format_list *format_list, long long u, int base)
{
    char    *ustr;

    if (format_list->mod.ll)
		ustr = ft_itoa_base(get_unsigned(u), base);
	else if (format_list->mod.l)
		ustr = ft_itoa_base((unsigned long)u, base);
	else if (format_list->mod.h)
		ustr = ft_itoa_base((unsigned short)u, base);
	else if (format_list->mod.hh)
		ustr = ft_itoa_base((unsigned char)u, base);
	else
		ustr = ft_itoa_base((unsigned int)u, base);
    return (ustr);
}

int     conv_base(char conv)
{
    if (conv == 'o')
        return (8);
    if (conv == 'u')
        return (10);
    if (conv == 'x' || conv == 'X')
        return (16);
    return (0);
}

void    ft_strcap(char *str)
{
    int     i;
    i = 0;
    while (str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
}

int     print_conv_ouxX(t_format_list *format_list)
{
    unsigned long long  u;
    char                *ustr;
    int                 count;

    count = 0;
    u = va_arg(*(format_list->ap), unsigned long long);
    ustr = get_str(format_list, u, conv_base(format_list->conv));
    if (format_list->conv == 'X')
        ft_strcap(ustr);
    if (format_list->precision_flag && !(format_list->flag.zero = 0))
    {
        if (u == 0 && format_list->precision == 0)
            ustr[0] = 0;
        ustr = add_prefix(ustr, format_list->precision - ft_strlen(ustr), '0');
    }
    else if (format_list->flag.zero && format_list->flag.minus == 0)
        ustr = add_prefix(ustr, format_list->width - ft_strlen(ustr), '0');
    if (format_list->flag.zero == 0 && format_list->flag.minus == 0)
        ustr = add_prefix(ustr, format_list->width - ft_strlen(ustr), ' ');
    if (format_list->flag.minus)
            ustr = add_suffix(ustr, format_list->width - ft_strlen(ustr), ' ');
    return (ft_putstrn(ustr, -1));
}