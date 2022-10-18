/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:09:26 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/27 15:09:26 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;
	t_list	*tmp;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}

void	freestacks(t_stacks *stacks)
{
	if (stacks->a)
		ft_lstclear(&stacks->a);
	if (stacks->b)
		ft_lstclear(&stacks->b);
	if (stacks)
		free(stacks);
}
