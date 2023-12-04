/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:42:21 by ahooghe           #+#    #+#             */
/*   Updated: 2023/06/05 06:42:22 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf MAPFILE\n", 2);
		return (-1);
	}
	if (parse_file(&data, argv[1]) == -1)
		return (-1);
	generate_map(&data);
	generate_iso_view(data.map);
	autoscale(data.map);
	data.animate_on = 0;
	if (start_mlx(&data) == -1)
		return (-1);
	return (0);
}
