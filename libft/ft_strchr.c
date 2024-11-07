/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:18:56 by ael-qori          #+#    #+#             */
/*   Updated: 2023/11/03 22:16:54 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char )character)
			return ((char *)(str + i));
		i++;
	}
	if ((char)character == 0)
		return ((char *)(str + i));
	return (NULL);
}
