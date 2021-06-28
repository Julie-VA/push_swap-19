/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:58:55 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/28 10:10:43 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	setstacks_split(char **argv, t_list **tmp, int i, int j)
{
	j++;
	while (argv[i][j] >= '0' && argv[i][j] <= '9')
		j++;
	if (argv[i][j] == ' ')
	{
		j++;
		if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-')
		{
			(*tmp)->next = (t_list *)malloc(sizeof(t_list));
			*tmp = (*tmp)->next;
		}
		return (j);
	}
	else if (!argv[i][j])
		return (j);
	else
	{
		(*tmp)->next = NULL;
		return (-1);
	}
}

static int	setstacks_gen_helper(int j, t_stacks *s)
{
	if (j == -1)
	{
		print_error(s);
		return (0);
	}
	else
		return (1);
}

static int	setstacks_gen(t_stacks *s, int *count, char **argv, t_list **tmp)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
			{
				(*tmp)->next = NULL;
				print_error(s);
				return (0);
			}
			(*tmp)->cont = ft_atoi(argv[i] + j, s, &j, tmp);
			(*count)++;
			if (j == -1)
				return (0);
			j = setstacks_split(argv, tmp, i, j);
			if (!setstacks_gen_helper(j, s))
				return (0);
		}
		if (argv[++i])
		{
			(*tmp)->next = (t_list *)malloc(sizeof(t_list));
			*tmp = (*tmp)->next;
		}
	}
	return (1);
}

t_stacks	*setstacks(char	**argv, int *count)
{
	t_stacks	*stacks;
	t_list		*tmp;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->a = (t_list *)malloc(sizeof(t_list));
	tmp = stacks->a;
	stacks->b = NULL;
	if (!setstacks_gen(stacks, count, argv, &tmp))
		return (NULL);
	tmp->next = NULL;
	return (stacks);
}
