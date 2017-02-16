/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:33:16 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/11/24 19:42:22 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr_s;
	size_t		i;

	i = -1;
	ptr_s = (const char *)s;
	while (++i < n)
		if (*(ptr_s + i) == (char)c)
			return ((void*)ptr_s + i);
	return (NULL);
}
