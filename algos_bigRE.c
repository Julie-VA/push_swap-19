/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_bigRE.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:36:27 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/14 10:46:12 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	end_algo_big()
{
	
}

void	algo_big(t_stacks *stacks, int count)
{
	int	*tab;
	int	part[5];
	int	i;
	int	j;
	int	loop;
	int check;
	int	max;
	int min;

	tab = lst_tab(stacks->a, count);
	j = 0;
	check = 0;
	while (ft_lstsize(stacks->a) > 8)
	{
		i = 0;
		while (i < 5)
			part[i++] = tab[j++];
		loop = 0;
		while (loop < 5)
		{
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
				while (1)
				{
					if (stacks->a->cont > max)
					{
						while (stacks->b->cont != max)
							rrb(stacks, 1);
						pb(stacks, 1);
						loop++;
						max = stacks->b->cont;
						break ;
					}
					if (stacks->a->cont < min)
					{
						while (stacks->b->cont != max)
							rrb(stacks, 1);
						pb(stacks, 1);
						loop++;
						min = stacks->b->cont;
						break ;
					}
					if (stacks->a->cont > stacks->b->cont && stacks->a->cont < ft_lstlast(stacks->b))
					{
						pb(stacks, 1);
						loop++;
						break ;
					}
					else
						rrb(stacks, 1);
				}
			}
			end_algo_big()
		}
	}
}