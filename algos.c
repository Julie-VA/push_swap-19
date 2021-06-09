/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 23:59:35 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/09 15:20:49 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_small(t_stacks *stacks, int count)
{
	int	*tab;
	int i;

	tab = lst_tab(stacks->a, count);
	i = 0;
	while (stacks->a->next->next->next)
	{
		if (stacks->a->cont == tab[i] && ++i)
			pb(stacks, 1);
		else if (stacks->a->next->cont == tab[i] && stacks->a->cont == tab[i + 1])
			sa(stacks, 1);
		else if (stacks->a->next->cont == tab[i] || stacks->a->next->next->cont == tab[i])
			ra(stacks, 1);
		else
			rra(stacks, 1);
	}
	free(tab);
	alg3(stacks);
	while (i-- > 0)
		pa(stacks, 1);
}
//bien pour les petits trucs

static int	is_in_part(int cont, int *part, int partsize)
{
	int	i;

	i = 0;
	while (i < partsize)
	{
		if (cont == part[i])
			return (1);
		i++;
	}
	return (0);
}

static int	end_big_algs(t_stacks *stacks, int *tab, int j, int size)
{
	while (ft_lstsize(stacks->a) <= size && ft_lstsize(stacks->a) > 3)
	{
		if (stacks->a->cont == tab[j])
		{
			j++;
			pb(stacks, 1);
		}
		else
			ra(stacks, 1);
		if (ft_lstsize(stacks->a) == 3)
		{
			alg3(stacks);
			return (1);	
		}
	}
	return (0);
}

void	alg_med(t_stacks *stacks, int count)
{
	int	*tab;
	int	part[3];
	int i;
	int	j;
	int	loop;

	tab = lst_tab(stacks->a, count);
	j = 0;
	while (stacks->a->next->next->next)
	{
		loop = 0;
		i = 0;
		while (i < 3)
			part[i++] = tab[j++];
		if (end_big_algs(stacks, tab, j - 3, 6) == 1)
			break ;
		while (loop < 3)
		{
			if (is_in_part(stacks->a->cont, part, 3) && ++loop)
				pb(stacks, 1);
			else if (is_in_part(stacks->a->next->cont, part, 3)
					|| is_in_part(stacks->a->next->next->cont, part, 3))
				ra(stacks, 1);
			else
				rra(stacks, 1);
			if (ft_lstsize(stacks->a) == 3)
				break ;
		}
		if (ft_lstsize(stacks->b) > 3)
			mod_rev_alg3(stacks);
		else
		{
			if (ft_lstsize(stacks->a) == 3)
				alg3(stacks);
			rev_alg3(stacks);
		}
	}
	free(tab);
	while (stacks->b)
		pa(stacks, 1);
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

	tab = lst_tab(stacks->a, count);
	j = 0;
	check = 0;
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
								rrb(stacks, 1);
							pb(stacks, 1);
							max = stacks->b->cont;
							break ;
						}
						if (stacks->a->cont > stacks->b->cont)
						{
							if (stacks->a->cont > ft_lstlast(stacks->b) && stacks->a->cont > ft_lstlast(stacks->b))
								pb(stacks, 1);
							else if (stacks->a->cont < ft_lstlast(stacks->b) && stacks->a->cont < ft_lstlast(stacks->b))
								pb(stacks, 1);
							break ;
						}
						if (stacks->b->cont > check)
						rb(stacks, 1);
					}
				}
			}
			else if (is_in_part(stacks->a->next->cont, part, 5)
					|| is_in_part(stacks->a->next->next->cont, part, 5))
				ra(stacks, 1);
			else
				rra(stacks, 1);
			if (ft_lstsize(stacks->a) == 3)
				break ;
		}
	}
	// alg3(stacks);
	free(tab);
	while (stacks->b)
		pa(stacks, 1);
}
