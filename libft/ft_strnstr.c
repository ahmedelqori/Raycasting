/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:51:13 by ael-qori          #+#    #+#             */
/*   Updated: 2023/11/10 11:18:21 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *set, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*set)
		return ((char *)(s1));
	while (i < n && s1[i])
	{
		j = 0;
		if (s1[i] == set[j])
		{
			while (set[j] && i + j < n && s1[i + j] == set[j])
				j++;
			if (set[j] == '\0')
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
