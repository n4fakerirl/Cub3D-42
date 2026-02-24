/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:39:27 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/17 14:13:01 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	msg_pos(t_data *data)
{
	if (data->info.cnt.count_in == 0 && data->info.cnt.count_in == 0
		&& data->info.cnt.other == 0)
		return (1);
	if (data->info.cnt.count_in == 1)
		ft_error("allowed positions : 'W', 'S', 'N', 'E'");
	if (data->info.cnt.count_in > 1)
		ft_error("multiple unknown letters found in map");
	if (data->info.cnt.count_nbrin > 0)
		ft_error("unknown digit found in map, '1' = walls, '0' = floor only");
	if (data->info.cnt.other > 0)
		ft_error("characters below map, map must be the last element");
	return (0);
}

void	countalnum(t_data *data, char c, int line)
{
	if (ft_isalpha(c))
	{
		if (c != 'N' && c != 'W' && c != 'S' && c != 'E'
			&& line <= data->info.lstline_pos)
			data->info.cnt.count_in++;
		else if (line > data->info.lstline_pos)
			data->info.cnt.other++;
	}
	else if (ft_isdigit(c))
	{
		if (c != '1' && c != '0' && line <= data->info.lstline_pos)
			data->info.cnt.count_nbrin++;
		else if (line > data->info.lstline_pos)
			data->info.cnt.other++;
	}
	else if (!ft_isspace(c))
		data->info.cnt.other++;
}

int	enough_fc(int c, int f)
{
	if (c == 1 && f == 1)
		return (1);
	if (c < 1)
		ft_error("ceiling configuration not found, 1 nedeed");
	if (c > 1)
		ft_error("found multiple ceiling configurations, 1 nedeed");
	if (f < 1)
		ft_error("floor configuration not found, 1 nedeed");
	if (f > 1)
		ft_error("found multiple floor configurations, 1 nedeed");
	return (0);
}

int	parse_ext(int n, int s, int w, int e)
{
	if (n == 1 && s == 1 && w == 1 && e == 1)
		return (1);
	if (n < 1)
		ft_error("north texture not found");
	else if (n > 1)
		ft_error("more than one north texture found, 1 needed");
	if (s < 1)
		ft_error("south texture not found");
	else if (s > 1)
		ft_error("more than one south texture found, 1 needed");
	if (e < 1)
		ft_error("east texture not found");
	else if (e > 1)
		ft_error("more than one east texture found, 1 needed");
	if (w < 1)
		ft_error("west texture not found");
	else if (w > 1)
		ft_error("more than one west texture found, 1 needed");
	return (0);
}

int	allowed_map(char c, int line, t_data *data)
{
	if (c == 'W' || c == 'S' || c == 'N' || c == 'E')
		return (1);
	else if (c == '\t' || c == ' ' || c == '\n' || c == '\r' || c == '\0')
		return (1);
	else if (c == '1' || c == '0')
		return (1);
	else
	{
		if (line < data->info.fstline_pos)
			ft_error("useless line above map");
		else if (line > data->info.lstline_pos)
			ft_error("useless line below map");
		else
			ft_error("useless line in map");
		return (0);
	}
}
