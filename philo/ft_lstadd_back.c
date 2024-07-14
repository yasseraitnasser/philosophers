/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <yait-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:08:28 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/14 20:03:31 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*tmp;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		new -> next = NULL;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp -> next = new;
}
