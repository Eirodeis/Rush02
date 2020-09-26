/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbonilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:27:07 by pbonilla          #+#    #+#             */
/*   Updated: 2020/09/26 20:05:04 by pbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definition.h"

int		add_to_dict(t_def **dictionary, char *buff,int l)
{
	int 	i;
	int 	j;
	char	*char_nbr;
	char	*str;
	unsigned long	nbr;

	char_nbr = malloc(sizeof(char) * 100);
	str = malloc(sizeof(char) * 100);
	j = 0;
	i = 0;

	while (buff[i] && buff[i] >= '0' && buff[i] <= '9')
	{
		char_nbr[i] = buff[i];
		++i;
	}
	char_nbr[i] = 0;
	while (buff[i] && (buff[i] == ' ' || buff[i] == ':'))
		++i;
	while (buff[i])
	{
		str[j] = buff[i];
		++j;
		++i;
	}
	str[j] = 0;
	nbr = ft_atoi(char_nbr);
	dictionary[l] = malloc(sizeof(t_def));
	dictionary[l]->nbr = nbr;
	dictionary[l]->str = str;
	return (0);
}

int		count_lines(int dict_file)
{
	char	c;
	int state;
	int lines;

	state = 0;
	lines = 0;
	while (read(dict_file, &c, 1) > 0)
	{

		if (c >= '0' && c <= '9' && state == 0)
		{
			state = 1;
		}
		else if (c == ':' && state == 1)
		{
			state = 2;
		}
		else if (c != ' ' && (c <= '0' || c >= '9') && state == 2)
		{
			++lines;
			state = 0;
		}

	}
	return (lines);
}

int		file_to_dict(t_def **dictionary, int dict_file)
{
	char			buff[1024];
	char			c;
	int				i,j,k,l;
	if (!(dictionary = malloc(sizeof(t_def**) * count_lines(dict_file))))
		return (put_error(2));
	close(dict_file);
	dict_file = open("numbers.dict", O_RDONLY);
	if (dict_file == -1)
		return (put_error(2));
	k = 0;
	l = 0;
	while (read(dict_file, &c, 1) > 0 )
	{
		if (c == '\n')
		{
			buff[k] = '\0';
			add_to_dict(dictionary, buff, l);
			k = 0;
			++l;
		}
		if (c != '\n')
		{
			buff[k] = c;
			++k;
		}
	}
	return (1);
}

int	main()
{
	t_def	**dictionary = NULL;
	int		dict_file;

	dict_file = open("numbers.dict", O_RDONLY);
	if (dict_file == -1)
		return (put_error(2));
	if (!file_to_dict(dictionary, dict_file))
		return (put_error(2));
	return (0);
}
