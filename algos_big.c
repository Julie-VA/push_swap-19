/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:36:27 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/14 15:37:51 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b_push(t_stacks *stacks, int *max, int *min)
{
	while (1)
	{
		if (stacks->a->cont > *max)
		{
			while (stacks->b->cont != *max)
				rrb(stacks, 1);
			pb(stacks, 1);
			*max = stacks->b->cont;
			break ;
		}
		if (stacks->a->cont < *min)
		{
			while (stacks->b->cont != *max)
				rrb(stacks, 1);
			pb(stacks, 1);
			*min = stacks->b->cont;
			break ;
		}
		if (stacks->a->cont > stacks->b->cont && stacks->a->cont < ft_lstlast(stacks->b))
		{
			pb(stacks, 1);
			break ;
		}
		else
			rb(stacks, 1);
	}
}

static int	algo_big_core(t_stacks *stacks, int *part)
{
	static int	max;
	static int 	min;
	int			loop;
	static int	check;

	loop = 0;
	while (loop < 5)
	{
		if (loop == 0 && check > 0)
		{
			if (get_half(stacks->a, part))
				check = 4;
			else
				check = 5;
		}
		if (check == 4)
			while (!is_in_part(stacks->a->cont, part, 5))
				ra(stacks, 1);
		else
			while (!is_in_part(stacks->a->cont, part, 5))
				rra(stacks, 1);
		if (loop <= 2 && check < 2)
		{
			pb(stacks, 1);
			loop++;
			check++;
			if (loop == 2 && stacks->b->cont < stacks->b->next->cont)
				sb(stacks, 1);
			max = stacks->b->cont;
			min = ft_lstlast(stacks->b);
		}
		else
		{
			sort_b_push(stacks, &max, &min);
			loop++;
		}
	}
	return (max);
}

void	algo_big(t_stacks *stacks, int count)
{
	int	*tab;
	int	part[5];
	int	i;
	int	j;
	int max;

	tab = lst_tab(stacks->a, count);
	j = 0;
	max = 0;
	while (ft_lstsize(stacks->a) > 8)
	{
		i = 0;
		while (i < 5)
			part[i++] = tab[j++];
		max = algo_big_core(stacks, part);
		
	}
	end_algo_big(stacks, tab, j, max);
	alg3(stacks);
	free(tab);
	while (stacks->b)
		pa(stacks, 1);
}
