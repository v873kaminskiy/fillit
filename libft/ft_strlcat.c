/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:25:28 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/11/28 21:34:32 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	int		j;

	i = ft_strlen(dst);
	j = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst + 1 > size)
		return (len_src + size);
	if (len_dst + 1 < size)
	{
		while (i < size - 1)
			*(dst + i++) = *(src + j++);
		*(dst + i) = '\0';
	}
	return (len_src + len_dst);
}
