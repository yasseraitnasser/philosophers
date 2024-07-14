/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:04:44 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/14 20:00:29 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(t_input *input, int i)
{
	t_philo *new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new -> input = input;
	new -> id = i + 1;
	new -> next = NULL;
	return (new);
}
