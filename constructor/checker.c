/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:57 by satushi           #+#    #+#             */
/*   Updated: 2023/03/23 14:01:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static bool	unlockfork(pthread_mutex_t *timech, pthread_mutex_t *diech)
{
	pthread_mutex_unlock(timech);
	pthread_mutex_unlock(diech);
	return (false);
}

static bool not_death(pthread_mutex_t *timech)
{
	pthread_mutex_unlock(timech);
	return (true);
}

static bool	philo_deathistrue(size_t *p_n, t_allinfo *info, long long *d_t)
{
	long	long	lvs;
	pthread_mutex_t	*timech;
	pthread_mutex_t	*diech;

	timech = &(info->timecheck_same[*p_n]);
	pthread_mutex_lock(timech);
	lvs = info->philoinfo[*p_n].philo_livedstart;
	if (getnowtime_ms() - lvs < *(d_t) * 1000)
		return (not_death(timech));
	diech = &(info->diecheck);
	pthread_mutex_lock(&(info->diecheck));
	if (info->philo_die_ornot == true)
		return (unlockfork(timech, diech));
	if (print_die(info, *p_n + 1, "died") == false)
		return (unlockfork(timech, diech));
	info->philo_die_ornot = true;
	return (unlockfork(timech, diech));
}

void	*philo_checker(void *info_i)
{
	size_t		philo_num;
	t_allinfo	*info;
	size_t		countup;
	long long	d_t;

	philo_num = 0;
	countup = 0;
	info = (t_allinfo *)info_i;
	d_t = info->philoinfo[philo_num].time_to_die;
	while (1)
	{
		while ((info->philoinfo)[countup].correctend == true)
		{
			countup++;
			if (countup == info->philo_num)
				return (NULL);
		}
		countup = 0;
		if ((info->philoinfo)[philo_num].correctend == false)
			if (philo_deathistrue(&philo_num, info, &d_t) == false)
				return (NULL);
		philo_num++;
		if (philo_num == info->philo_num)
			philo_num = 0;
		usleep(200);
	}
	return (NULL);
}
