/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:17:18 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/02 09:48:04 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stacks *stacks, int mod)
{
	t_list	*tmp;

	tmp = stacks->b;
	stacks->b = stacks->b->next;
	tmp->next = stacks->a;
	stacks->a = tmp;
	if (mod)
		write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stacks *stacks, int mod)
{
	t_list	*tmp;

	tmp = stacks->a;
	stacks->a = stacks->a->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
	if (mod)
		write(1, "pb\n", 3);
	return (1);
}
