/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:34:51 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/12/28 15:52:07 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *data, size_t data_size)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		return (NULL);
	if (!data)
	{
		list->data = NULL;
		list->data_size = 0;
	}
	else
	{
		if (!(list->data = malloc(data_size)))
			return (NULL);
		list->data = ft_memcpy(list->data, data, data_size);
		list->data_size = data_size;
	}
	list->next = NULL;
	return (list);
}
