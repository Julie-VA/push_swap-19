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

static void	make_part(int *tab, int *part)
{
	int			i;
	static int	j;

	i = 0;
	while (i < 20)
		part[i++] = tab[j++];
}

static int	get_rot(t_stacks *stacks, int *part, int size)
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

void	algo(t_stacks *stacks, int count)
{
	int	*tab;
	int	part[20];
	int	rotate;

	tab = lst_tab(stacks->a, count);
	// while (ft_lstsize(stacks->a) > 0)
	// {
		make_part(tab, part);
		rotate = get_rot(stacks, part, ft_lstsize(stacks->a));
		while (rotate > 0)
		{
			ra(stacks, 1);
			rotate--;
		}
		while (rotate < 0)
		{
			rra(stacks, 1);
			rotate++;
		}
	// }
	free(tab);
}