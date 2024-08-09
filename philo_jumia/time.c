/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:30:37 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/06 17:33:16 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(long time)
{
	struct timeval	tv;
	long	tmp;

	gettimeofday(&tv, NULL);
	tmp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (tmp - time);
}
