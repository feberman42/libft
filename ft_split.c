/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:09:07 by feberman          #+#    #+#             */
/*   Updated: 2023/05/10 14:36:33 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *str, char c)
{
	int	i;
	int	word_count;

	word_count = 0;
	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			word_count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (word_count);
}

static int	ft_word_len(const char *str, char end)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != end)
		i++;
	return (i);
}

static int	ft_split_words(const char *s, const char c, char **split, int wc)
{
	int	i;
	int	word;
	int	wordlen;

	word = 0;
	i = 0;
	while (word < wc)
	{
		while (s[i] == c)
			i++;
		wordlen = ft_word_len(s + i, c);
		split[word] = malloc(wordlen + 1);
		if (split[word] == 0)
			return (0);
		ft_strlcpy(split[word], s + i, wordlen + 1);
		i += wordlen;
		word++;
	}
	return (1);
}

static void	ft_free_split(char **split, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word_count;

	word_count = ft_word_count(s, c);
	split = malloc(sizeof(char *) * (word_count + 1));
	if (split == 0)
		return (split);
	split[word_count] = 0;
	if (ft_split_words(s, c, split, word_count) != 1)
	{
		ft_free_split(split, word_count);
		return (0);
	}
	return (split);
}
