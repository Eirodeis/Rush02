/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbonilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:33:42 by pbonilla          #+#    #+#             */
/*   Updated: 2020/09/24 19:29:50 by pbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			is_separator(char c, char *charset)
{
	int i;

	i = -1;
	if (!charset)
		return (1);
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

int			count_nb_words(char *str, char *charset)
{
	int i;
	int nb_word;

	i = -1;
	nb_word = 0;
	while (str[++i])
	{
		if (is_separator(str[i], charset) && str[i - 1] &&
				!is_separator(str[i - 1], charset))
			++nb_word;
	}
	if (!is_separator(str[i - 1], charset) ||
			!str[i - 1])
		++nb_word;
	return (nb_word);
}

void		fill_tab(char *str, char *subtab, int start, int end)
{
	int i;

	i = 0;
	while (start != end)
	{
		subtab[i] = str[start];
		++start;
		++i;
	}
	subtab[i] = 0;
}

void		malloc_sub_tabs(char *str, char **splitey, char *charset)
{
	int i;
	int j;
	int i_char;

	i = -1;
	j = 0;
	i_char = 0;
	while (str[++i])
	{
		if (is_separator(str[i], charset) && (str[i - 1] &&
					!is_separator(str[i - 1], charset)))
		{
			splitey[i_char] = malloc(sizeof(*splitey) * (i - j + 1));
			fill_tab(str, splitey[i_char], j, i);
			++i_char;
			j = i;
		}
		if (is_separator(str[i], charset))
			j = i + 1;
	}
	if (!is_separator(str[i - 1], charset))
	{
		splitey[i_char] = malloc(sizeof(*splitey) * (i - j + 1));
		fill_tab(str, splitey[i_char], j, i);
	}
}

char		**ft_split(char *str, char *charset)
{
	char	**splitey;
	int		nb_words;

	nb_words = count_nb_words(str, charset);
	if (!(splitey = malloc(sizeof(char **) * (nb_words + 1))))
		return (NULL);
	malloc_sub_tabs(str, splitey, charset);
	splitey[nb_words] = 0;
	return (splitey);
}
