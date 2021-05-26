/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:02:55 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/26 11:32:16 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checkspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static void	checksign(const char *nptr, int *i, int *sign)
{
	if (nptr[*i] == '-')
	{
		*sign = 1;
		*i += 1;
	}
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	int				i;
	long long int	rtrnval;

	sign = 0;
	i = 0;
	rtrnval = 0;
	while (checkspace(nptr[i]))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
		checksign(nptr, &i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		rtrnval = (rtrnval * 10) + (nptr[i++] - '0');
	if (sign == 1)
		rtrnval *= -1;
	if (sign == 0 && rtrnval < 0)
		return (-1);
	else if (sign == 1 && rtrnval > 0)
		return (0);
	return ((int)rtrnval);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;
	t_list	*temp;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	*lst = NULL;
}
