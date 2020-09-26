/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbonilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:08:04 by pbonilla          #+#    #+#             */
/*   Updated: 2020/09/26 19:04:43 by pbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_DEF
#define RUSH_DEF

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		put_error(int error);
int		sgn(char signe);
int		ft_atoi(char *str);
int			is_separator(char c, char *charset);
int			count_nb_words(char *str, char *charset);
void		fill_tab(char *str, char *subtab, int start, int end);
void		malloc_sub_tabs(char *str, char **splitey, char *charset);
char		**ft_split(char *str, char *charset);
typedef struct s_definition
{
	unsigned long		nbr;
	char				*str;
}	t_def;

#endif
