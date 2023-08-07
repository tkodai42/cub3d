/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:22:10 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/11 17:13:22 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_pass_name(t_player *p, char *argv[])
{
	int		i;
	int		error;

	error = 1;
	i = 0;
	while (argv[1][i])
	{
		i++;
	}
	if (i <= 4)
		ft_error(p, ERROR_PAS);
	if (argv[1][i - 4] == '.')
		if (argv[1][i - 3] == 'c')
			if (argv[1][i - 2] == 'u')
				if (argv[1][i - 1] == 'b')
					error = 0;
	if (error == 1)
		ft_error(p, ERROR_PAS);
	p->pass_ptr = argv[1];
}

void	ft_check_args(t_player *p, int argc, char *argv[])
{
	if (!(argc == 2 || argc == 3))
		ft_error(p, ERROR_ARGS);
	p->save = 0;
	if (argc == 3)
	{
		if (argv[2][0] == '-')
			if (argv[2][1] == '-')
				if (argv[2][2] == 's')
					if (argv[2][3] == 'a')
						if (argv[2][4] == 'v')
							if (argv[2][5] == 'e')
								if (argv[2][6] == '\0')
									p->save = 1;
		if (p->save == 0)
			ft_error(p, ERROR_ARGS);
	}
	ft_check_pass_name(p, argv);
}
