/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:19:42 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/19 14:07:03 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

/*int	main(void)
{
	printf("str -> %s\n", get_next_line(0));
	return (0);
}*/

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	if (ac != 2)
	{
		printf("Usage: %s <file_name>", av[0]);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	line = NULL;
	while ((line = get_next_line(fd)))
	{
		printf("line %d ; str -> %s\n\n", i, line);
		free(line);
		i++;
	}
	return (0);
}
