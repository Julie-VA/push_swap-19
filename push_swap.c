/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:57:15 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/07 14:41:54 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	printlst(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("end=%d\n", lst->cont);
// 		lst = lst->next;
// 	}
// 	printf("\n");
// }

static void	selectalgo(t_stacks *stacks, int count)
{
	if (count == 2)
		sa(stacks, 1);
	else if (count == 3)
		alg3(stacks);
	else if (count == 4)
		alg4(stacks);
	else if (count == 5 || count == 6)
		alg5_6(stacks, count);
	else if (count <= 11)
		algo_small(stacks, count);
	else
		algo(stacks, count);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			count;
	(void)argc;

	stacks = setstacks(argv, &count);
	if (!stacks)
	{
		// system("leaks push_swap");
		return (0);
	}
	if (dupcheck(stacks->a))
	{
		print_error(stacks);
		// system("leaks push_swap");
		return (0);
	}
	if (!sorted(stacks->a, count))
		return (0);
	else
		selectalgo(stacks, count);
	// printlst(stacks->a); //to remove
	// printlst(stacks->b); //to remove
	freestacks(stacks);
	// system("leaks push_swap");
	return (0);
}
