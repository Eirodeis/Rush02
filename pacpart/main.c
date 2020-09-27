/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbonilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:27:07 by pbonilla          #+#    #+#             */
/*   Updated: 2020/09/27 11:21:12 by pbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definition.h"

char		*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = -1;
	if (!(dup = malloc(sizeof(*dup) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[++i])
		dup[i] = src[i];
	dup[i] = 0;
	return (dup);
}

int		add_to_dict(t_def **dictionary, char *buff,int l)
{
	int 	i;
	int 	j;
	char	*nbr;
	char	*str;

	nbr = malloc(sizeof(char*) * 100);
	str = malloc(sizeof(char*) * 100);
	j = 0;
	i = 0;

	while (buff[i] && buff[i] >= '0' && buff[i] <= '9')
	{
		nbr[i] = buff[i];
		++i;
	}
	nbr[i] = 0;
	while (buff[i] && (buff[i] == ' ' || buff[i] == ':'))
		++i;
	while (buff[i])
	{
		str[j] = buff[i];
		++j;
		++i;
	}
	str[j] = 0;
	dictionary[l] = malloc(sizeof(t_def*));
	dictionary[l]->nbr = ft_strdup(nbr);
	dictionary[l]->str = ft_strdup(str);
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
	printf("nb lignes = %d\n", lines);
	return (lines);
}

int		file_to_dict(t_def **dictionary, int dict_file)
{
	char			buff[1024];
	char			c;
	int				i,j,k,l;

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
	t_def	**dictionary;
	int		dict_file;

	dict_file = open("numbers.dict", O_RDONLY);
	if (dict_file == -1)
		return (put_error(2));
	if (!(dictionary = malloc(sizeof(t_def**) * count_lines(dict_file))))
		return (put_error(2));
	if (!file_to_dict(dictionary, dict_file))
		return (put_error(2));
	int i = 0;
	while (++i < 40)
		printf("%s , %s\n",dictionary[i]->nbr, dictionary[i]->str);
	return (0);
}
