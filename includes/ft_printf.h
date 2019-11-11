/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:26:05 by matruman          #+#    #+#             */
/*   Updated: 2019/11/06 13:29:54 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

struct				s_flag
{
	char	hash;
	char	zero;
	char	space;
	char	plus;
	char	minus;
};

struct				s_mod
{
	char	h;
	char	hh;
	char	l;
	char	ll;
	char	bl;
};

typedef struct		s_format_list
{
	const char				*format;
	va_list					*ap;
	char					*insert;
	char					conv;
	struct s_flag			flag;
	struct s_mod			mod;
	int						position;
	int						len;
	int						width;
	int						precision;
	char					precision_flag;
	struct s_format_list	*next;
}					t_format_list;

t_format_list		*get_format_list(const char *format, va_list *ap);
int					get_format(const char *format, t_format_list *format_list);
int					isconv(char c);
int					isflag(char c);
int					ismod(char c);
char				*ft_itoa_base(unsigned long long value, int base);
unsigned long long	get_unsigned(long long value);
int					print_format_list(t_format_list *format_list);
int					print_conv_di(t_format_list *format_list);
int					print_conv_pouxx(t_format_list *format_list);
int					print_conv_cp(t_format_list *format_list);
int					print_conv_s(t_format_list *format_list);
char				*add_prefix(char *str, int count, char c);
char    			*add_suffix(char *str, int count, char c);
int					ft_printf(const char *format, ...);
void				ft_strcap(char *str);

#endif
