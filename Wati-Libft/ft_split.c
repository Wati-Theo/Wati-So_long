/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:15:28 by tschlege          #+#    #+#             */
/*   Updated: 2021/11/26 15:29:19 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freebox(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static	size_t	ft_word_count(char const *s, char c)
{
	int		i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] == (unsigned char)c)
			i++;
		while (s[i] && s[i] != (unsigned char)c)
			i++;
		if (!s[i] && s[i - 1] != (unsigned char)c)
			wc++;
		wc++;
	}
	return (wc);
}

static	int	ft_word_len(char const *s, char c, int *start)
{
	size_t	word_len;

	word_len = 0;
	while (s[*start] == (unsigned char)c)
		*start = *start + 1;
	while (s[*start] && s[*start] != (unsigned char)c)
	{
		*start = *start + 1;
		word_len++;
	}
	if (s[*start] == (unsigned char)c || !s[*start])
		return (word_len);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	wc;
	char	**str;
	int		start;
	size_t	word_len;
	size_t	i;

	if (!s)
		return (NULL);
	wc = ft_word_count(s, c);
	if (!wc)
		return (ft_calloc(1, sizeof(char *)));
	str = ft_calloc(wc, sizeof(char *));
	if (!str)
		return (NULL);
	start = 0;
	i = 0;
	while (i + 1 < wc)
	{
		word_len = ft_word_len(s, c, &start);
		str[i] = ft_substr(s, start - word_len, word_len);
		if (!str[i++])
			return (ft_freebox(str));
	}
	str[i] = 0;
	return (str);
}
