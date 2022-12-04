/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suplayerko <suplayerko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:56 by suplayerko          #+#    #+#             */
/*   Updated: 2022/12/01 18:48:48 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 t_data	*malloc_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		clean_exit(data, -1);
	return (data);
}

int	main(int argc, char *argv[])
{
	t_data		*data;
	data = NULL;
	if (argc != 2)
	{
		error_msg("Needs a path to one file (only)");
		clean_exit(data, -2);
	}
	else
	{
		data = malloc_data();
		data->window = malloc(sizeof(t_window));
		window_init(data);
		parse_file(argv[1], data);
		cub3d_render(data);
		clean_exit(data, 0);
	}
}
