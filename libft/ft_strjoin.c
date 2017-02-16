/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:11:20 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/11/24 17:24:38 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_new;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str_new = ft_strnew(len_s1 + len_s2);
	if (!str_new)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len_s1)
		*(str_new + i) = *(s1 + i);
	while (++j < len_s2)
		*(str_new + i + j) = *(s2 + j);
	return (str_new);
}
