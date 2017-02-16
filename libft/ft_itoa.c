/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:16:30 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/11/30 16:14:53 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len(int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	n_cp;

	len = ft_len(n);
	n_cp = n;
	if (n < 0)
	{
		n_cp = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = n_cp % 10 + '0';
	while (n_cp /= 10)
		str[--len] = n_cp % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
