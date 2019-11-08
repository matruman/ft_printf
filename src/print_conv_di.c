/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:57:51 by matruman          #+#    #+#             */
/*   Updated: 2019/11/06 14:57:54 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char    *get_str(t_format_list *format_list, long long d)
{
    char    *dstr;

    if (format_list->mod.ll)
		dstr = ft_itoa_base(get_unsigned(d), 10);
	else if (format_list->mod.l)
		dstr = ft_itoa_base(get_unsigned((long)d), 10);
	else if (format_list->mod.h)
		dstr = ft_itoa_base(get_unsigned((short)d), 10);
	else if (format_list->mod.hh)
		dstr = ft_itoa_base(get_unsigned((char)d), 10);
	else
		dstr = ft_itoa_base(get_unsigned((int)d), 10);
    return (dstr);
}

char    *add_prefix(char *str, int count, char c)
{
    char    *zero_str;
    char    *res;

    if (count <= 0)
        return (str);
    zero_str = ft_strnew(count);
    ft_memset(zero_str, c, count);
    res = ft_strjoin(zero_str, str);
    free(str);
    free(zero_str);
    return (res);
}

char    *add_suffix(char *str, int count, char c)
{
    char    *zero_str;
    char    *res;

    if (count <= 0)
        return (str);
    zero_str = ft_strnew(count);
    ft_memset(zero_str, c, count);
    res = ft_strjoin(str, zero_str);
    free(str);
    free(zero_str);
    return (res);
}


int		print_conv_di(t_format_list *format_list)
{
	long long	d;
	int			count;
    char        *dstr;
    char        sign;

	d = va_arg(*(format_list->ap), long long);
    sign = (d < 0) ? '-' : '+';
    dstr = get_str(format_list, d);
    if (format_list->precision_flag && !(format_list->flag.zero = 0))
    {
        if (d == 0 && format_list->precision == 0)
            dstr[0] = 0;
        dstr = add_prefix(dstr, format_list->precision - ft_strlen(dstr), '0');
    }
    else if (format_list->flag.zero && format_list->flag.minus == 0)
        dstr = add_prefix(dstr, format_list->width - (format_list->flag.space
        || format_list->flag.plus || (sign == '-'))  - ft_strlen(dstr), '0');
    if (sign == '-' || format_list->flag.plus)
        dstr = add_prefix(dstr, 1, sign);
    if (sign == '+' && format_list->flag.space && (sign = ' '))
        dstr = add_prefix(dstr, 1, sign);
    if (format_list->flag.zero == 0 && format_list->flag.minus == 0)
        dstr = add_prefix(dstr, format_list->width - ft_strlen(dstr), ' ');
    if (format_list->flag.minus)
            dstr = add_suffix(dstr, format_list->width - ft_strlen(dstr), ' ');
    return (ft_putstrn(dstr, -1));
}
