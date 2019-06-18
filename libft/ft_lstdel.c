/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:40:59 by vbrazas           #+#    #+#             */
/*   Updated: 2019/06/18 17:48:03 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*next_list;

	if (!alst || *alst == NULL || !del)
		return ;
	list = *alst;
	while (list)
	{
		next_list = list->next;
		del(list->content, list->content_size);
		free(list);
		list = next_list;
	}
	*alst = NULL;
}
