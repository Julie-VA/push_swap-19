/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:33:49 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/02 09:50:20 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	printlst(t_list *lst)
{
	printf("\n");
	while (lst)
	{
		printf("%d\n", lst->cont);
		lst = lst->next;
	}
}

static int	selectope(char *line, t_stacks *stacks)
{
	int	check;

	check = 0;
	if (!ft_strcmp(line, "sa"))
		check = sa(stacks, 0);
	else if (!ft_strcmp(line, "sb"))
		check = sb(stacks, 0);
	else if (!ft_strcmp(line, "ss"))
		check = ss(stacks, 0);
	else if (!ft_strcmp(line, "pa"))
		check = pa(stacks, 0);
	else if (!ft_strcmp(line, "pb"))
		check = pb(stacks, 0);
	else if (!ft_strcmp(line, "ra"))
		check = ra(stacks, 0);
	else if (!ft_strcmp(line, "rb"))
		check = rb(stacks, 0);
	else if (!ft_strcmp(line, "rr"))
		check = rr(stacks, 0);
	else if (!ft_strcmp(line, "rra"))
		check = rra(stacks, 0);
	else if (!ft_strcmp(line, "rrb"))
		check = rrb(stacks, 0);
	else if (!ft_strcmp(line, "rrr"))
		check = rrr(stacks, 0);
	return (check);
}

int	main(int argc, char	**argv)
{
	t_stacks	*stacks;
	char		*line;
	int			count;
	(void)argc;

	stacks = setstacks(argv, &count);
	if (!stacks)
	{
		// system("leaks checker");
		return (0);
	}
	if (dupcheck(stacks->a))
	{
		print_error(stacks);
		// system("leaks checker");
		return (0);
	}
	while (get_next_line(0, &line))
	{
		if (!selectope(line, stacks))
		{
			print_error(stacks);
			// system("leaks checker");
			return (0);
		}
		free(line);
	}
	if (sorted(stacks->a, count))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	printlst(stacks->a); //to remove
	printlst(stacks->b); //to remove
	freestacks(stacks);
	// system("leaks checker");
	return (0);
}
