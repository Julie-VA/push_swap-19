/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:18:02 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/02 09:50:07 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stacks *stacks, int mod)
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
	if (mod)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stacks *stacks, int mod)
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
	if (mod)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stacks *stacks, int mod)
{
	ra(stacks, mod);
	rb(stacks, mod);
	return (1);
}
