/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_bh_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:04:38 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/21 16:04:38 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_stacks *stacks, int val, int mod, int write)
{
	while (val > 0)
	{
		if (mod == 0)
			ra(stacks, write);
		else if (mod == 1)
			rb(stacks, write);
		val--;
	}
	while (val < 0)
	{
		if (mod == 0)
			rra(stacks, write);
		else if (mod == 1)
			rrb(stacks, write);
		val++;
	}
}

void	rotate_b(t_stacks *stacks, int *max, int *min, int rota)
{
	int	rotb;

	if (stacks->a->cont > *max || stacks->a->cont < *min)
	{
		rotb = get_rot_b_max(stacks, *max, ft_lstsize(stacks->b));
		rotate_ab(stacks, rotb, 1, 0);
		write_rotations(rota, rotb);
		if (stacks->a->cont > *max)
			*max = stacks->a->cont;
		else if (stacks->a->cont < *min)
			*min = stacks->a->cont;
		pb(stacks, 1);
	}
	else
	{
		rotb = get_rot_b(stacks, stacks->a->cont, ft_lstsize(stacks->b));
		rotate_ab(stacks, rotb, 1, 0);
		write_rotations(rota, rotb);
		pb(stacks, 1);
	}
}

void	empty_b(t_stacks *stacks, int *max, int *min, int rota)
{
	while (rota > 0)
	{
		write(1, "ra\n", 3);
		rota--;
	}
	while (rota < 0)
	{
		write(1, "rra\n", 4);
		rota++;
	}
	if (ft_lstsize(stacks->b) == 0)
		pb(stacks, 1);
	else if (ft_lstsize(stacks->b) == 1)
	{
		pb(stacks, 1);
		if (stacks->b->cont < stacks->b->next->cont)
			sb(stacks, 1);
	}
	*max = stacks->b->cont;
	if (ft_lstsize(stacks->b) == 2)
		*min = stacks->b->next->cont;
}

void	make_part(int *tab, int *part, int partsize)
{
	int			i;
	static int	j;

	i = 0;
	while (i < partsize)
		part[i++] = tab[j++];
}
