/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destoroy_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:46:40 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/26 19:46:40 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	destoroy_forks_error(t_allinfo *info, size_t i)
{
	size_t	f_n;

	f_n = 0;
	while (f_n != i)
	{
		pthread_mutex_destroy(&info->forks[f_n]);
		f_n++;
	}
}

void	destoroy_forks(t_allinfo *info)
{
	size_t	f_n;
	size_t	pn;

	f_n = 0;
	pn = info->philo_num;
	while (f_n != pn)
	{
		pthread_mutex_destroy(&info->forks[f_n]);
		f_n++;
	}
}
