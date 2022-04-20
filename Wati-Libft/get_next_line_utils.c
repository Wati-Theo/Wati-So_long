/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:42:51 by Wati-Theo         #+#    #+#             */
/*   Updated: 2022/04/20 22:25:54 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sp_ft_strndup(char *str, int size)
{
	char	*cpy;
	int		i;

	cpy = malloc((size + 1) * sizeof(char) + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cpy[i] = str[i];
		i++;
	}
	// cpy[i] = '\n';
	cpy[i] = 0;
	return (cpy);
}

int	where_are_you(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_freejoin(char const *s1, char const *s2)
{
	size_t	stotal_len;
	char	*the_nouvelle;
	int		i;
	int		j;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	stotal_len = ft_strlen(s1) + ft_strlen(s2);
	the_nouvelle = ft_calloc(stotal_len + 1, sizeof(char));
	if (!the_nouvelle)
		return (NULL);
	while (s1[i])
		the_nouvelle[j++] = s1[i++];
	i = 0;
	while (s2[i])
		the_nouvelle[j++] = s2[i++];
	the_nouvelle[j] = '\0';
	free((void *)s1);
	return (the_nouvelle);
}

void	get_back(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i])
		i++;
	i++;
	while (buf[i])
	{
		buf[j] = buf[i];
		i++;
		j++;
	}
	buf[j] = 0;
}
