/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:54:10 by ael-qori          #+#    #+#             */
/*   Updated: 2023/11/10 10:59:20 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow_pos(char c, int sign, int i)
{
	if ((i == 18 && c >= '7') || (i >= 19))
	{
		if (sign == -1 && (c >= '8' || i >= 19))
			return (0);
		else if (sign == 1)
			return (-1);
	}
	return (1);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\v' || c == '\r'
		|| c == '\t' || c == '\n' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *s)
{
	long long int	number;
	int				sign;
	int				i;

	number = 0;
	sign = 1;
	i = 0;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && *s == '0')
		s++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (ft_overflow_pos(s[i], sign, i) != 1)
			return (ft_overflow_pos(s[i], sign, i));
		number = (number * 10) + (s[i++] - 48);
	}
	return (number * sign);
}
