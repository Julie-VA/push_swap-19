/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_huge_rotate_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:37:22 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/21 15:16:56 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rot_a_huge(t_stacks *stacks, int *part, int size)
{
	t_list	*tmp;
	int		i;
	int		top;
	int		bottom;

	tmp = stacks->a;
	i = 0;
	while (tmp)
	{
		if (is_in_part(tmp->cont, part, 40))
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
		if (is_in_part(tmp->cont, part, 40))
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
