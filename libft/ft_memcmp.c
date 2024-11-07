/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:51:52 by ael-qori          #+#    #+#             */
/*   Updated: 2023/11/04 17:55:03 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *)s1;
	s = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*f != *s)
			return (*f - *s);
		f++;
		s++;
	}
	return (0);
}
