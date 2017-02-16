/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:52 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/11/28 20:30:39 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	int		new_len;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s) - 1;
	while (*(s + i) == ' ' || *(s + i) == '\t' || *(s + i) == '\n')
		i++;
	while (*(s + j) == ' ' || *(s + j) == '\t' || *(s + j) == '\n')
		j--;
	if (i == (int)ft_strlen(s))
		new_len = 0;
	else
		new_len = ft_strlen(s) - i - (ft_strlen(s) - j) + 1;
	str = ft_strnew(new_len);
	if (!str)
		return (NULL);
	while (i <= j)
		*(str + k++) = *(s + i++);
	return (str);
}
