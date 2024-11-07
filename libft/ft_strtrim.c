/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:45:49 by ael-qori          #+#    #+#             */
/*   Updated: 2023/11/14 12:02:56 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, const char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static char	*put_str(const char *s1, int len)
{
	char	*s;
	int		i;

	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*s;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	while (*s1 && check(*s1, set))
		s1++;
	len = ft_strlen(s1);
	if (!len)
		return (ft_strdup(""));
	while (s1[len - 1] && check(s1[len - 1], set))
		len--;
	s = put_str(s1, len);
	if (!s)
		return (NULL);
	return (s);
}
