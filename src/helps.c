/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:26:52 by matruman          #+#    #+#             */
/*   Updated: 2019/11/06 13:34:11 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				isconv(char	c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
			c == 'c' || c == 's' || c == 'p' || c == 'f' || c == '%')
		return (1);
	else
		return (0);
}

int				isflag(char c)
{
	if (c == '#' || c == '0' || c == ' ' || c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int				ismod(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	else
		return (0);
}

char	*add_prefix(char *str, int count, char c)
{
	char	*zero_str;
	char	*res;

	if (count <= 0)
		return (str);
	zero_str = ft_strnew(count);
	ft_memset(zero_str, c, count);
	res = ft_strjoin(zero_str, str);
	free(str);
	free(zero_str);
	return (res);
}

char	*add_suffix(char *str, int count, char c)
{
	char	*zero_str;
	char	*res;

	if (count <= 0)
		return (str);
	zero_str = ft_strnew(count);
	ft_memset(zero_str, c, count);
	res = ft_strjoin(str, zero_str);
	free(str);
	free(zero_str);
	return (res);
}

void	ft_strcap(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}
