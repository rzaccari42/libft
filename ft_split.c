/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:07:14 by razaccar          #+#    #+#             */
/*   Updated: 2023/12/15 11:18:27 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static int	ft_wordlen(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_count_word(char const *str, char c)
{
	_Bool	is_in_word;
	int		i;
	int		nb_word;

	i = -1;
	is_in_word = false;
	nb_word = 0;
	if (c == '\0' && str[0] == '\0')
		return (0);
	else if (c == '\0')
		return (1);
	while (str[++i])
	{
		if (str[i] == c)
			is_in_word = false;
		else
		{
			if (!is_in_word)
			{
				is_in_word = true;
				nb_word++;
			}
		}
	}
	return (nb_word);
}

static char	**ft_free_split(char **split, int nb_word)
{
	int	i;

	i = 0;
	if (!split)
		return (NULL);
	while (i < nb_word)
	{
		if (split[i])
			free(split[i++]);
	}
	free(split);
	return (NULL);
}

static char	**ft_fill_split(char const *str, char c, char ***split, int nb_word)
{
	int		i;
	int		j;
	_Bool	is_in_word;

	i = -1;
	j = 0;
	is_in_word = false;
	while (j < nb_word)
	{
		if (str[++i] == c)
		{
			is_in_word = false;
			continue ;
		}
		if (!is_in_word)
		{
			is_in_word = true;
			(*split)[j] = malloc(sizeof(char) * (ft_wordlen(&str[i], c) + 1));
			if (!(*split)[j])
				return (ft_free_split(*split, (j - 1)));
			ft_strlcpy((*split)[j++], &str[i], (ft_wordlen(&str[i], c) + 1));
		}
	}
	return (*split);
}

char	**ft_split(char const *str, char c)
{
	int		nb_word;
	char	**split;

	if (!str)
		return (NULL);
	nb_word = ft_count_word(str, c);
	split = malloc(sizeof(char *) * (nb_word + 1));
	if (!split)
		return (NULL);
	split = ft_fill_split(str, c, &split, nb_word);
	split[nb_word] = NULL;
	return (split);
}
