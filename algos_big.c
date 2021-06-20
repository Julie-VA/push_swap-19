/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_re.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:26:22 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/17 17:26:22 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_ab(t_stacks *stacks, int val, int mod)
{
	if (mod == 0)
	{
		while (val > 0)
		{
			ra(stacks, 1);
			val--;
		}
		while (val < 0)
		{
			rra(stacks, 1);
			val++;
		}
	}
	else if (mod == 1)
	{
		while (val > 0)
		{
			rb(stacks, 1);
			val--;
		}
		while (val < 0)
		{
			rrb(stacks, 1);
			val++;
		}
	}
}

static void	empty_b(t_stacks *stacks, int *max, int *min)
{
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

static void	make_part(int *tab, int *part, int partsize)
{
	int			i;
	static int	j;

	i = 0;
	while (i < partsize)
		part[i++] = tab[j++];
}

static int	end_algo(t_stacks *stacks, int *part, int max, int min)
{
	int	loop;
	int	partsize;

	loop = 0;
	partsize = ft_lstsize(stacks->a);
	while (loop < partsize)
	{
		rotate_ab(stacks, get_rot_a(stacks, part, ft_lstsize(stacks->a)), 0);
		if (ft_lstsize(stacks->b) < 2)
			empty_b(stacks, &max, &min);
		else
		{
			if (stacks->a->cont > max || stacks->a->cont < min)
			{
				rotate_ab(stacks, get_rot_b_max(stacks, max, ft_lstsize(stacks->b)), 1);
				if (stacks->a->cont > max)
					max = stacks->a->cont;
				else if (stacks->a->cont < min)
					min = stacks->a->cont;
				pb(stacks, 1);
			}
			else
			{
				rotate_ab(stacks, get_rot_b(stacks, stacks->a->cont, ft_lstsize(stacks->b)), 1);
				pb(stacks, 1);
			}
		}
		loop++;
	}
	return (max);
}

void	algo_big(t_stacks *stacks, int count)
{
	int	*tab;
	int	part[20];
	int	max;
	int	min;
	int	loop;

	tab = lst_tab(stacks->a, count);
	max = 0;
	min = 0;
	loop = 0;
	while (ft_lstsize(stacks->a) > 0)
	{
		make_part(tab, part, 20);
		loop = 0;
		while (loop < 20)
		{
			rotate_ab(stacks, get_rot_a(stacks, part, ft_lstsize(stacks->a)), 0);
			if (ft_lstsize(stacks->b) < 2)
				empty_b(stacks, &max, &min);
			else
			{
				if (stacks->a->cont > max || stacks->a->cont < min)
				{
					rotate_ab(stacks, get_rot_b_max(stacks, max, ft_lstsize(stacks->b)), 1);
					if (stacks->a->cont > max)
						max = stacks->a->cont;
					else if (stacks->a->cont < min)
						min = stacks->a->cont;
					pb(stacks, 1);
				}
				else
				{
					rotate_ab(stacks, get_rot_b(stacks, stacks->a->cont, ft_lstsize(stacks->b)), 1);
					pb(stacks, 1);
				}
			}
			loop++;
		}
		if (ft_lstsize(stacks->a) < 20 && ft_lstsize(stacks->a) > 0)
		{
			make_part(tab, part, ft_lstsize(stacks->a));
			max = end_algo(stacks, part, max, min);
		}
	}
	free(tab);
	rotate_ab(stacks, get_rot_b_max(stacks, max, ft_lstsize(stacks->b)), 1);
	while (stacks->b)
		pa(stacks, 1);
}