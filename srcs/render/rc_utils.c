/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:36:44 by gule-bat          #+#    #+#             */
/*   Updated: 2025/12/09 19:36:44 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	lenght(float x, float y)
{
	float	dist;

	dist = 0;
	dist = sqrt(x * x + y * y);
	return (dist);
}

int	get_color(int r, int g, int b)
{
	int	color;

	color = 255 << 24;
	color = color | (r << 16);
	color = color | (g << 8);
	color = color | (b);
	return (color);
}
