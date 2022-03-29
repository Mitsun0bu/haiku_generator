/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:25:47 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/21 22:30:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c);
static int		ft_calloc_strs(char const *s, char c, char **tab);
static void		ft_fill_tab(char const *s, char c, char **tab);

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**tab;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	tab = ft_calloc(words + 1, sizeof(char *));
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	if (!ft_calloc_strs(s, c, tab))
	{
		ft_free_double_tab(tab);
		return (NULL);
	}
	ft_fill_tab(s, c, tab);
	return (tab);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			word ++;
		if (s[i] != c && s[i + 1] == '\0')
			word ++;
		i ++;
	}
	return (word);
}

static int	ft_calloc_strs(char const *s, char c, char **tab)
{
	int	i;
	int	i_tab;
	int	j_tab;

	i = 0;
	i_tab = 0;
	while (s[i] && i_tab < ft_count_words(s, c))
	{
		while (s[i] == c)
			i ++;
		j_tab = 0;
		while (s[i] != c && s[i + 1] != '\0')
		{
			j_tab ++;
			i ++;
		}
		if (s[i] != c && s[i + 1] == '\0')
			j_tab ++;
		tab[i_tab] = ft_calloc(j_tab + 1, sizeof(char));
		if (!tab[i_tab])
			return (0);
		i_tab ++;
		i ++;
	}
	return (1);
}

static void	ft_fill_tab(char const *s, char c, char **tab)
{
	int	i;
	int	i_tab;
	int	j_tab;

	i = 0;
	i_tab = 0;
	while (s[i] && i_tab < ft_count_words(s, c))
	{
		j_tab = 0;
		while (s[i] == c)
			i ++;
		while (s[i] != c && s[i + 1] != '\0')
			tab[i_tab][j_tab++] = s[i++];
		if (s[i] != c && s[i + 1] == '\0')
			tab[i_tab][j_tab++] = s[i];
		tab[i_tab][j_tab] = '\0';
		i_tab ++;
		i ++;
	}
}