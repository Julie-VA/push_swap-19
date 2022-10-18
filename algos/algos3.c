/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:05:16 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/27 16:04:52 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg3(t_stacks *s)
{
	if (s->a->cont > s->a->next->cont
		&& s->a->next->cont < s->a->next->next->cont
		&& s->a->cont < s->a->next->next->cont)
		sa(s, 1);
	if (s->a->cont > s->a->next->cont
		&& s->a->next->cont < s->a->next->next->cont
		&& s->a->cont > s->a->next->next->cont)
		ra(s, 1);
	if (s->a->cont < s->a->next->cont
		&& s->a->next->cont > s->a->next->next->cont
		&& s->a->cont > s->a->next->next->cont)
		rra(s, 1);
	if (s->a->cont < s->a->next->cont
		&& s->a->next->cont > s->a->next->next->cont
		&& s->a->cont < s->a->next->next->cont)
	{
		rra(s, 1);
		sa(s, 1);
	}
	if (s->a->cont > s->a->next->cont
		&& s->a->next->cont > s->a->next->next->cont)
	{
		sa(s, 1);
		rra(s, 1);
	}
}

void	rev_alg3(t_stacks *s)
{
	if (s->b->cont < s->b->next->cont
		&& s->b->next->cont > s->b->next->next->cont
		&& s->b->cont > s->b->next->next->cont)
		sb(s, 1);
	if (s->b->cont < s->b->next->cont
		&& s->b->next->cont > s->b->next->next->cont
		&& s->b->cont < s->b->next->next->cont)
		rb(s, 1);
	if (s->b->cont > s->b->next->cont
		&& s->b->next->cont < s->b->next->next->cont
		&& s->b->cont < s->b->next->next->cont)
		rrb(s, 1);
	if (s->b->cont > s->b->next->cont
		&& s->b->next->cont < s->b->next->next->cont
		&& s->b->cont > s->b->next->next->cont)
	{
		rrb(s, 1);
		sb(s, 1);
	}
	if (s->b->cont < s->b->next->cont
		&& s->b->next->cont < s->b->next->next->cont)
	{
		sb(s, 1);
		rrb(s, 1);
	}
}

static void	mod_rev_alg3_part2(t_stacks *s)
{
	if (s->b->cont > s->b->next->cont
		&& s->b->next->cont < s->b->next->next->cont
		&& s->b->cont > s->b->next->next->cont)
	{
		rb(s, 1);
		sb(s, 1);
		rrb(s, 1);
	}
	if (s->b->cont < s->b->next->cont
		&& s->b->next->cont < s->b->next->next->cont)
	{
		sb(s, 1);
		rb(s, 1);
		sb(s, 1);
		rrb(s, 1);
		sb(s, 1);
	}
}

void	mod_rev_alg3(t_stacks *s)
{
	if (s->b->cont < s->b->next->cont
		&& s->b->next->cont > s->b->next->next->cont
		&& s->b->cont > s->b->next->next->cont)
		sb(s, 1);
	if (s->b->cont < s->b->next->cont
		&& s->b->next->cont > s->b->next->next->cont
		&& s->b->cont < s->b->next->next->cont)
	{
		sb(s, 1);
		rb(s, 1);
		sb(s, 1);
		rrb(s, 1);
	}
	if (s->b->cont > s->b->next->cont
		&& s->b->next->cont < s->b->next->next->cont
		&& s->b->cont < s->b->next->next->cont)
	{
		rb(s, 1);
		sb(s, 1);
		rrb(s, 1);
		sb(s, 1);
	}
	mod_rev_alg3_part2(s);
}
