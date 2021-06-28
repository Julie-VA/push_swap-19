/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:58:55 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/28 10:21:37 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	setstacks_split(char **argv, t_list **tmp, int i, int *j)
{
	(*j)++;
	while (argv[i][*j] >= '0' && argv[i][*j] <= '9')
		(*j)++;
	if (argv[i][*j] == ' ')
	{
		(*j)++;
		if ((argv[i][*j] >= '0' && argv[i][*j] <= '9') || argv[i][*j] == '-')
		{
			(*tmp)->next = (t_list *)malloc(sizeof(t_list));
			*tmp = (*tmp)->next;
		}
		return (1);
	}
	else if (!argv[i][*j])
		return (1);
	else
	{
		(*tmp)->next = NULL;
		return (0);
	}
}

static int	not_number(t_list **tmp, char **argv, int i, int j)
{
	if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
	{
		(*tmp)->next = NULL;
		return (0);
	}
	else
		return (1);
}

static int	setstacks_gen(int *count, char **argv, t_list **tmp)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!not_number(tmp, argv, i, j))
				return (0);
			(*tmp)->cont = ft_atoi(argv[i] + j, &j, tmp);
			(*count)++;
			if (j == -1)
				return (0);
			if (!setstacks_split(argv, tmp, i, &j))
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
	if (!setstacks_gen(count, argv, &tmp))
	{
		print_error(stacks);
		return (NULL);
	}
	tmp->next = NULL;
	return (stacks);
}
