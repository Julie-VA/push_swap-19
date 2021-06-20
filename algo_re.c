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

static void	make_part(int *tab, int *part)
{
	int			i;
	static int	j;

	i = 0;
	while (i < 20)
		part[i++] = tab[j++];
}

static int	get_rot_a(t_stacks *stacks, int *part, int size)
{
	t_list	*tmp;
	int		i;
	int		top;
	int		bottom;

	tmp = stacks->a;
	i = 0;
	while (tmp)
	{
		if (is_in_part(tmp->cont, part, 20))
		{
			top = i;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	tmp = stacks->a;
	i = 0;
	while (tmp)
	{
		if (is_in_part(tmp->cont, part, 20))
			bottom = i;
		i++;
		tmp = tmp->next;
	}
	bottom = size - bottom;
	if (top < bottom)
		return (top);
	else
		return (-bottom);
}

static int	get_rot_b_max(t_stacks *stacks, int max, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stacks->b;
	i = 0;
	while (tmp)
	{
		if (tmp->cont == max)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i > size / 2)
		return (-(size - i));
	else
		return (i);
}

static int	get_rot_b(t_stacks *stacks, int cont, int size)
{
	t_stacks	*tmp;
	int			i;
	int			icpy;

	tmp = stacks;
	i = 0;
	while (i < size)
	{
		if (cont > tmp->b->cont && cont < ft_lstlast(tmp->b))
			break ;
		i++;
		rb(tmp, 0);
	}
	icpy = i;
	while (icpy)
	{
		rrb(tmp, 0);
		icpy--;
	}
	if (i > size / 2)
		return (-(size - i));
	else
		return (i);
}

void	algo(t_stacks *stacks, int count)
{
	int	*tab;
	int	part[20];
	int	rotate;
	int	max;
	int	min;
	int	loop;

	tab = lst_tab(stacks->a, count);
	max = 0;
	min = 0;
	loop = 0;
	while (ft_lstsize(stacks->a) > 0)
	{
		make_part(tab, part);
		loop = 0;
		while (loop < 20)
		{
			rotate = get_rot_a(stacks, part, ft_lstsize(stacks->a));
			rotate_ab(stacks, rotate, 0);
			if (ft_lstsize(stacks->b) < 2)
				empty_b(stacks, &max, &min);
			else
			{
				if (stacks->a->cont > max || stacks->a->cont < min)
				{
					rotate = get_rot_b_max(stacks, max, ft_lstsize(stacks->b));
					rotate_ab(stacks, rotate, 1);
					if (stacks->a->cont > max)
						max = stacks->a->cont;
					else if (stacks->a->cont < min)
						min = stacks->a->cont;
					pb(stacks, 1);
				}
				else
				{
					rotate = get_rot_b(stacks, stacks->a->cont, ft_lstsize(stacks->b));
					rotate_ab(stacks, rotate, 1);
					pb(stacks, 1);
				}
			}
			loop++;
		}
	}
	free(tab);
	rotate = get_rot_b_max(stacks, max, ft_lstsize(stacks->b));
	rotate_ab(stacks, rotate, 1);
	while (stacks->b)
		pa(stacks, 1);
}