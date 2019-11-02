/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:26:05 by matruman          #+#    #+#             */
/*   Updated: 2019/11/02 16:16:02 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
# include "libft.h"

typedef struct		s_format_list
{
	const char				*format;
	char					*insert;
	char					conv;
	char					*flags;
	char					*mod;
	int						position;
	int						len;
	int						width;
	int						precision;
	struct s_format_list	*next;
}					t_format_list;

t_format_list	*get_format_list(const char *format);
int				get_format(const char *format, t_format_list *format_list);
int				isconv(char c);
int				isflag(char c);
int				ismod(char c);

#endif
