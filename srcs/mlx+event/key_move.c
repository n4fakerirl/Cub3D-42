/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:10:56 by gule-bat          #+#    #+#             */
/*   Updated: 2025/11/04 17:10:56 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_move(int key, t_data *data)
{
	if (key == 122)
		data->player.z = 1;
	if (key == 113)
		data->player.q = 1;
	if (key == 115)
		data->player.s = 1;
	if (key == 100)
		data->player.d = 1;
	if (key == 65363)
		data->player.r = 1;
	if (key == 65361)
		data->player.l = 1;
	return (1);
}
// 65363
// 65361
// printf("%d\n", key);

int	unkey_move(int key, t_data *data)
{
	if (key == 122)
		data->player.z = 0;
	if (key == 113)
		data->player.q = 0;
	if (key == 115)
		data->player.s = 0;
	if (key == 100)
		data->player.d = 0;
	if (key == 65363)
		data->player.r = 0;
	if (key == 65361)
		data->player.l = 0;
	return (1);
}
