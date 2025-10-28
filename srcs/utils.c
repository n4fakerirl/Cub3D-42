/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:49:30 by ocviller          #+#    #+#             */
/*   Updated: 2025/10/28 11:51:16 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(char *message)
{
	ft_putstr_fd("cub3d: error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}
