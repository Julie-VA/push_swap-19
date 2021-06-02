/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:45:26 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/02 09:25:02 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_stacks *stacks)
{
	write(1, "Error\n", 6);
	freestacks(stacks);
}

int	dupcheck(t_list	*a)
{
	int		n;
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = a;
	tmp2 = a;
	while (tmp1)
	{
		n = tmp1->cont;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (n == tmp2->cont)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	sorted(t_list *a, int count)
{
	int	i;

	i = 1;
	while (a->next)
	{
		if (a->cont > a->next->cont)
			return (1);
		a = a->next;
		i++;
	}
	if (i != count)
		return (1);
	return (0);
}