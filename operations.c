/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:27:17 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/26 15:36:28 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->a->cont;
	stacks->a->cont = stacks->a->next->cont;
	stacks->a->next->cont = tmp;
}

void	sb(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->b->cont;
	stacks->b->cont = stacks->b->next->cont;
	stacks->b->next->cont = tmp;
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_stacks *stacks)
{
	t_list	*tmp;

	tmp = stacks->b;
	stacks->b = stacks->b->next;
	tmp->next = stacks->a;
	stacks->a = tmp;
}

void	pb(t_stacks *stacks)
{
	t_list	*tmp;

	tmp = stacks->a;
	stacks->a = stacks->a->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
}

void	ra(t_stacks *stacks)
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
}

void	rb(t_stacks *stacks)
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
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}

void	rra(t_stacks *stacks)
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
}

void	rrb(t_stacks *stacks)
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
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
