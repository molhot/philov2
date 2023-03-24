/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:57 by satushi           #+#    #+#             */
/*   Updated: 2023/03/24 17:03:47 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static bool	unlockfork(pthread_mutex_t *timech, pthread_mutex_t *diech)
{
	pthread_mutex_unlock(timech);
	pthread_mutex_unlock(diech);
	return (false);
}

static bool	not_death(pthread_mutex_t *timech)
{
	pthread_mutex_unlock(timech);
	return (true);
}

static bool	philo_deathistrue(size_t *p_n, t_allinfo *info, long long *d_t)
{
	long long		lvs;
	pthread_mutex_t	*timech;
	pthread_mutex_t	*diech;

	timech = &(info->philoinfo[*p_n].timecheck_same);
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

static bool	philo_satisfied(t_allinfo *info)
{
	size_t	countup;
	size_t	all_pn;

	countup = 0;
	all_pn = info->philo_num;
	while (countup != all_pn)
	{
		pthread_mutex_lock(&(info->philoinfo)[countup].eat_ch);
		if ((info->philoinfo)[countup].correctend == false)
			return (false);
		pthread_mutex_unlock(&(info->philoinfo)[countup].eat_ch);
		countup++;
	}
	return (true);
}

void	*philo_checker(void *info_i)
{
	size_t		philo_num;
	t_allinfo	*info;
	long long	d_t;

	philo_num = 0;
	info = (t_allinfo *)info_i;
	d_t = info->philoinfo[philo_num].time_to_die;
	while (1)
	{
		if (philo_satisfied(info) == true)
			return (NULL);
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
