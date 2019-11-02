/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:55:58 by matruman          #+#    #+#             */
/*   Updated: 2019/09/20 17:58:24 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	res = (s1 && s2) ? (char *)malloc(ft_strlen(s1)
			+ ft_strlen(s2) + 1) : (char *)NULL;
	if (res)
	{
		i = 0;
		j = 0;
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			res[i] = s2[j];
			i++;
			j++;
		}
		res[i] = 0;
	}
	return (res);
}
