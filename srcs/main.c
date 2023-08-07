/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:05:26 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/10 13:18:31 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_player p;

	setvbuf(stdout, (char *)NULL, _IONBF, 0);
	p.is_bonus = 0;
	ft_check_args(&p, argc, argv);
	ft_cub3d(&p);
	return (0);
}
