/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:44:43 by tschlege          #+#    #+#             */
/*   Updated: 2021/11/26 15:37:38 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*retturn;

	retturn = b;
	while (len)
	{
		len--;
		*((unsigned char *)b + len) = (unsigned char)c;
	}
	return (retturn);
}
