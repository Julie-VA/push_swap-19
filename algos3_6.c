/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos3_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:56:40 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/05 01:02:26 by rvan-aud         ###   ########.fr       */
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

void	alg4(t_stacks *stacks)
{
	pb(stacks, 1);
	pb(stacks, 1);
	if (stacks->a->cont > stacks->a->next->cont
		&& stacks->b->cont < stacks->b->next->cont)
		ss(stacks, 1);
	else
	{
		if (stacks->a->cont > stacks->a->next->cont)
			sa(stacks, 1);
		if (stacks->b->cont < stacks->b->next->cont)
			sb(stacks, 1);
	}
	pa(stacks, 1);
	if (stacks->a->cont > stacks->a->next->next->cont)
	{
		if (stacks->b->cont < stacks->a->next->next->cont)
			ra(stacks, 1);
		else
		{
			pa(stacks, 1);
			ra(stacks, 1);
			ra(stacks, 1);
			return ;
		}
	}
	else if (stacks->a->cont > stacks->a->next->cont)
		sa(stacks, 1);
	pa(stacks, 1);
	if (stacks->a->cont > stacks->a->next->cont)
		sa(stacks, 1);
}

void	alg5_6(t_stacks *stacks, int count)
{
	int	*tab;
	int	check;

	tab = lst_tab(stacks->a, count);
	if (count == 5)
		check = 1;
	if (count == 6)
		check = 0;
	while (check < 3)
	{
		if (stacks->a->cont < tab[count - 3] && ++check)
			pb(stacks, 1);
		else if (stacks->a->next->cont < tab[count - 3])
			ra(stacks, 1);
		else
			rra(stacks, 1);
	}
	alg3(stacks);
	if (count == 5 && stacks->b->cont < stacks->b->next->cont)
		sb(stacks, 1);
	else if (count == 6)
		rev_alg3(stacks);
	if (count == 5)
		check--;
	while (check-- > 0)
		pa(stacks, 1);
}
