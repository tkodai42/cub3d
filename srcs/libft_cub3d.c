/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:04:18 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 12:05:27 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str && str[len])
	{
		len++;
	}
	return (len);
}

int		ft_strchr(char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char *ret_str;
	char *dest;

	ret_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 2));
	if (!ret_str)
		return (NULL);
	dest = ret_str;
	while (str1 && *str1)
	{
		*dest++ = *str1++;
	}
	while (str2 && *str2)
	{
		*dest++ = *str2++;
	}
	*dest++ = '\0';
	*dest = '\0';
	return (ret_str);
}

char	*ft_strdup(char *str)
{
	char *ret_str;
	char *dest;

	ret_str = malloc(sizeof(char) + ft_strlen(str) + 1);
	if (ret_str == NULL)
		return (NULL);
	dest = ret_str;
	while (str && *str)
	{
		*dest++ = *str++;
	}
	*dest = '\0';
	return (ret_str);
}
