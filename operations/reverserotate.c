/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:18:33 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/31 14:06:01 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*i;

	i = stacks->a;
	while (i->next->next)
		i = i->next;
	tmp = i->next;
	i->next = NULL;
	tmp->next = stacks->a;
	stacks->a = tmp;
	return (1);
}

int	rrb(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*i;

	i = stacks->b;
	while (i->next->next)
		i = i->next;
	tmp = i->next;
	i->next = NULL;
	tmp->next = stacks->b;
	stacks->b = tmp;
	return (1);
}

int	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	return (1);
}
