/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:05:16 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/07 10:18:03 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		//fake rb for 3
	}
	if (s->b->cont > s->b->next->cont
		&& s->b->next->cont < s->b->next->next->cont
		&& s->b->cont < s->b->next->next->cont)
	{
		rb(s, 1);
		sb(s, 1);
		rrb(s, 1);
		//fake rrb for 3
	}
	if (s->b->cont > s->b->next->cont
		&& s->b->next->cont < s->b->next->next->cont
		&& s->b->cont > s->b->next->next->cont)
	{
		rb(s, 1);
		sb(s, 1);
		rrb(s, 1);
		//fake rrb for 3
	}
	if (s->b->cont < s->b->next->cont
		&& s->b->next->cont < s->b->next->next->cont)
	{
		rb(s, 1);
		sb(s, 1);
		rrb(s, 1);
		//fake rrb for 3
	}
}
