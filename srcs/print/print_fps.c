/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:26:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/28 20:27:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/time.h>

static double	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

void	print_fps(void)
{
	static size_t	print_rate = 0;
	static double	time = 0.0;
	double			old_time;
	double			frame_time;

	old_time = time;
	time = get_time();
	frame_time = (time - old_time) / 1000.0;
	++print_rate;
	if (print_rate % 10 == 0)
		printf("FPS: %.0lf\n", 1.0 / frame_time);
}
