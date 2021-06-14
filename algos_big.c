/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:16:20 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/14 10:28:32 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
// 	int		size;

// 	size = ft_lstsize(stacks->a);
// 	if (get_half_ra(stacks, part, size) > get_half_rra(stacks, part, size))
// 		return (1);
// 	else
// 		return (0);
// }

static void	write_more_rra(int rracount, int rrbcount)
{
	while (rracount > rrbcount)
	{
		write(1, "rra\n", 4);
		rracount--;
	}
	while(rracount > 0)
	{
		write(1, "rrr\n", 4);
		rracount--;
	}
}

static void	write_less_rra(int rracount, int rrbcount)
{
	while (rracount > 0)
	{
		write(1, "rrr\n", 4);
		rracount--;
	}
	while (rrbcount > 0)
	{
		write(1, "rrb\n", 4);
		rrbcount--;
	}
}

static void	write_normal_rra(int rracount, int rrbcount)
{
	while (rracount > 0)
	{
		write(1, "rra\n", 4);
		rracount--;
	}
	while (rrbcount > 0)
	{
		write(1, "rrb\n", 4);
		rrbcount--;
	}
}

void	algo(t_stacks *stacks, int count)
{
	int	*tab;
	int	part[5];
	int i;
	int	j;
	int	loop;
	int	check;
	int	max;
	int	rracount;
	int	rrbcount;

	tab = lst_tab(stacks->a, count);
	j = 0;
	check = 0;
	rracount = 0;
	rrbcount = 0;
	while (stacks->a->next->next->next)
	{
		loop = 0;
		i = 0;
		while (i < 5)
			part[i++] = tab[j++];
		if (ft_lstsize(stacks->a) <= 5 + 3)
			while (stacks->b->cont != max)
				rrb(stacks, 1);
		if (end_big_algs(stacks, tab, j - 5, 5 + 3) == 1)
			break ;
		while (loop < 5)
		{
			if (is_in_part(stacks->a->cont, part, 5) && ++loop)
			{
				if (loop <= 2 && check < 2)
				{
					pb(stacks, 1);
					if (loop == 2 && stacks->b->cont < stacks->b->next->cont)
						sb(stacks, 1);
					if (loop == 2)
						max = stacks->b->cont;
					check++;
				}
				else
				{
					while (1)
					{
						if (stacks->a->cont > max)
						{
							while (stacks->b->cont != max)
							{
								rrb(stacks, 0);
								rrbcount++;
							}
							if (rracount > rrbcount)
								write_more_rra(rracount, rrbcount);
							else if (rrbcount && rracount)
								write_less_rra(rracount, rrbcount);
							else
								write_normal_rra(rracount, rrbcount);
							pb(stacks, 1);
							max = stacks->b->cont;
							rracount = 0;
							rrbcount = 0;
							break ;
						}
						if (stacks->a->cont > stacks->b->cont)
						{
							if (stacks->a->cont > ft_lstlast(stacks->b))
								pb(stacks, 1);
							break ;
						}
						else if (check < 5 && stacks->a->cont < max && stacks->a->cont < ft_lstlast(stacks->b))
						{
							while (stacks->b->cont != max)
							{
								rrb(stacks, 0);
								rrbcount++;
							}
							if (rracount > rrbcount)
								write_more_rra(rracount, rrbcount);
							else if (rrbcount && rracount)
								write_less_rra(rracount, rrbcount);
							else
								write_normal_rra(rracount, rrbcount);
							pb(stacks, 1);
							max = stacks->b->cont;
							rracount = 0;
							rrbcount = 0;
							break ;
						}
						else
							rb(stacks, 1);
					}
				}
			}
			else if (is_in_part(stacks->a->next->cont, part, 5)
					|| is_in_part(stacks->a->next->next->cont, part, 5))
				ra(stacks, 1);
			else
				while (!is_in_part(stacks->a->cont, part, 5))
				{
					rra(stacks, 0);
					rracount++;
				}
			if (loop == 5)
				check = 5;
			if (ft_lstsize(stacks->a) == 3)
				break ;
		}
	}
	alg3(stacks);
	free(tab);
	while (stacks->b)
		pa(stacks, 1);
}
