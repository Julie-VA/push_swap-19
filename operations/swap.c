/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:16:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/06 16:39:00 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stacks *stacks, int mod)
{
	int	tmp;

	tmp = stacks->a->cont;
	stacks->a->cont = stacks->a->next->cont;
	stacks->a->next->cont = tmp;
	if (mod)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stacks *stacks, int mod)
{
	int	tmp;

	tmp = stacks->b->cont;
	stacks->b->cont = stacks->b->next->cont;
	stacks->b->next->cont = tmp;
	if (mod)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stacks *stacks, int mod)
{
	sa(stacks, 0);
	sb(stacks, 0);
	if (mod)
		write(1, "ss\n", 3);
	return (1);
}
