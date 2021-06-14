/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_bigRE.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:36:27 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/14 11:48:23 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//

// static int	get_half_ra(t_stacks *stacks, int *part, int size)
// {
// 	int		i;
// 	t_list	*tmp;

// 	i = 0;
// 	tmp = stacks->a;
// 	while (i < size / 2)
// 	{
// 		if (tmp->cont == part[0] || tmp->cont == part[1] || tmp->cont == part[2]
// 			|| tmp->cont == part[3] || tmp->cont == part[4])
// 			return (i);
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	return (-1);
// }

// static int	get_half_rra(t_stacks *stacks, int *part, int size)
// {
// 	int		i;
// 	t_list	*tmp;

// 	i = 0;
// 	tmp = stacks->a;
// 	while (i < size / 2)
// 	{
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	while (tmp)
// 	{
// 		if (tmp->cont == part[0] || tmp->cont == part[1] || tmp->cont == part[2]
// 			|| tmp->cont == part[3] || tmp->cont == part[4])
// 			return (size - i);
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	return (-1);
// }

// static int	get_half(t_stacks *stacks, int *part)
// {
// 	int	size;
// 	int	rtnra;
// 	int	rtnrra;

// 	size = ft_lstsize(stacks->a);
// 	rtnra = get_half_ra(stacks, part, size);
// 	rtnrra = get_half_rra(stacks, part, size);
// 	if (rtnra < rtnrra && rtnra > 0)
// 		return (1);
// 	else
// 		return (0);
// }

//

static void	end_algo_big(t_stacks *stacks, int *tab, int j, int max)
{
	while (stacks->b->cont != max)
		rrb(stacks, 1);
	while (ft_lstsize(stacks->a) > 3)
	{
		while (stacks->a->cont != tab[j])
		{
			if (stacks->a->next->cont == tab[j] || stacks->a->next->next->cont == tab[j])
				ra(stacks, 1);
			else
				rra(stacks, 1);
		}
		pb(stacks, 1);
		j++;
	}
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
			// if (loop == 0 && check > 0)
			// {
			// 	if (get_half(stacks, part))
			// 		check = 5;
			// 	else
			// 		check = 4;
			// }
			// if (check == 4)
			// 	while (!is_in_part(stacks->a->cont, part, 5))
			// 		ra(stacks, 1);
			// else
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
						max = stacks->b->cont;
						break ;
					}
					if (stacks->a->cont < min)
					{
						while (stacks->b->cont != max)
							rrb(stacks, 1);
						pb(stacks, 1);
						min = stacks->b->cont;
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
				loop++;
			}
		}
	}
	end_algo_big(stacks, tab, j, max);
	alg3(stacks);
	free(tab);
	while (stacks->b)
		pa(stacks, 1);
}