/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_background_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:23:30 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/11 17:02:35 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_num_from_line2(char *line, t_color_check *cc)
{
	while (ft_strchr("1234567890", *line))
	{
		cc->c2 = cc->c2 * 10 + *line - '0';
		line++;
		cc->c2_exists = 1;
		if (cc->c2 > 255)
			return (1);
	}
	if (ft_strchr(",", *line))
		line++;
	while (ft_strchr("1234567890", *line))
	{
		cc->c3 = cc->c3 * 10 + *line - '0';
		line++;
		cc->c3_exists = 1;
		if (cc->c3 > 255)
			return (1);
	}
	if (*line != '\0')
		return (1);
	return (0);
}

int		get_num_from_line(char *line, t_color_check *cc)
{
	int		rv;

	while (ft_strchr("FC", *line))
		line++;
	while (ft_strchr(" ", *line))
		line++;
	while (ft_strchr("1234567890", *line))
	{
		cc->c1 = cc->c1 * 10 + *line - '0';
		line++;
		cc->c1_exists = 1;
		if (cc->c1 > 255)
			return (1);
	}
	if (ft_strchr(",", *line))
		line++;
	rv = get_num_from_line2(line, cc);
	return (rv);
}

int		get_background_colors(t_player *p, char *line, int f_c)
{
	t_color_check	cc;

	cc.c1 = 0;
	cc.c2 = 0;
	cc.c3 = 0;
	cc.c1_exists = 0;
	cc.c2_exists = 0;
	cc.c3_exists = 0;
	if (get_num_from_line(line, &cc))
		ft_error(p, 9);
	cc.c4 = cc.c1 * 256 * 256;
	cc.c4 += cc.c2 * 256;
	cc.c4 += cc.c3;
	if (!cc.c1_exists || !cc.c2_exists || !cc.c3_exists)
		ft_error(p, 9);
	if (f_c == 'F')
		p->floor_color = cc.c4;
	else
		p->loof_color = cc.c4;
	return (0);
}
