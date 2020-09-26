/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbonilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:27:45 by pbonilla          #+#    #+#             */
/*   Updated: 2020/09/26 20:00:24 by pbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int		put_error(int error)
{
	if (error == 1)
		ft_putstr("Error\n");
	else if (error == 2)
		ft_putstr("Dict Error\n");
	return (0);
}

#include <stdio.h>

int		ft_atoi(char *str)
{
	int 			i;
	unsigned long 	nbr;
	

	i = 0;
	nbr = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr = (10 * nbr) + (str[i] - 48);
		i++;
	}
	return (nbr);
}
