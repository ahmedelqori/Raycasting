/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:16 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/21 15:06:04 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	verify_extension(char *arg)
{
	if (ft_strlen(arg) <= 4)
		return (0);
	return (ft_strcmp_1(arg + ft_strlen(arg) - 4, ".cub"));
}

int	ft_parsing(char *argument, t_parsing *data)
{
	char	**file;

	if (!verify_extension(argument))
		return (write(2, "Error\nEnter a valid map file\n", 30), 0);
	file = get_file(argument);
	file = ft_verify_content(file, data);
	if (!file)
		return (write(2, "Error\nEnter a valid map file\n", 30), 0);
	if (!ft_verify_data(file, data) || !ft_verify_map(data))
	{
		free_buffer(file, 1);
		return (write(2, "Error\nEnter a valid map file\n", 30), 0);
	}
	free_buffer(file, 1);
	return (1);
}
