/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:02:00 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/21 15:09:56 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	**get_file(char *string)
{
	int		fd;
	int		i;
	char	*str;
	char	**file;

	file = malloc(MAX_LINE * sizeof(char *));
	i = 0;
	fd = open(string, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 7);
		perror(string);
		exit(1);
	}
	str = ft_substr(get_next_line(fd));
	while (str)
	{
		file[i++] = str;
		str = ft_substr(get_next_line(fd));
	}
	file[i++] = str;
	return (file);
}
