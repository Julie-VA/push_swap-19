/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:18:02 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/31 14:05:40 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*i;

	tmp = stacks->a;
	i = tmp;
	stacks->a = stacks->a->next;
	while (i->next)
		i = i->next;
	i->next = tmp;
	i->next->next = NULL;
	return (1);
}

int	rb(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*i;

	tmp = stacks->b;
	i = tmp;
	stacks->b = stacks->b->next;
	while (i->next)
		i = i->next;
	i->next = tmp;
	i->next->next = NULL;
	return (1);
}

int	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	return (1);
}
