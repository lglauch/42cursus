/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:32:34 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/22 14:54:47 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "fractol.h"
#include <stdio.h> //delete this line laterrrrrr

int	ft_compare_input(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	int			len_1;
	int			len_2;

	i = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if (!s1 && !s2 && n == 0)
		return (0);
	if (len_1 != len_2)
		return (1);
	while ((((unsigned char *)s1)[i] != 0 || ((unsigned char *)s2)[i] != 0)
		&& i + 1 < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			break ;
		i++;
	}
	if (i < n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

int	check_julia(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 4 && !ft_compare_input(argv[1], "julia", 5))
	{
		while (argv[2][i] != '\0')
		{
			if (ft_isdigit(argv[2][i]) == 0)
				return (1);
			i++;
		}
		i = 0;
		while (argv[3][i] != '\0')
		{
			if (ft_isdigit(argv[3][i]) == 0)
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}
