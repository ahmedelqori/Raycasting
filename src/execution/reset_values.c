/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:03:59 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/11 10:08:51 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	initialize_to_zero(t_container *container)
{
	ft_memset(&container->mouvements, 0, sizeof(container->mouvements));
	ft_memset(&container->player, 1, sizeof(t_playerentity));
}
