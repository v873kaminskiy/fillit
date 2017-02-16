/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:12:34 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/11/23 16:22:54 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptr_dst;
	char	*ptr_src;

	ptr_dst = (char*)dst;
	ptr_src = (char*)src;
	i = -1;
	if (ptr_src < ptr_dst)
		while ((int)--len >= 0)
			*(ptr_dst + len) = *(ptr_src + len);
	else
		while (++i < len)
			*(ptr_dst + i) = *(ptr_src + i);
	return (dst);
}
