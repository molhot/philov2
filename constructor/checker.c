/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:57 by satushi           #+#    #+#             */
/*   Updated: 2023/03/26 22:36:16 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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
		return (unlock_all(timech, diech));
	if (print_die(info, *p_n + 1, "died") == false)
		return (unlock_all(timech, diech));
	info->philo_die_ornot = true;
	return (unlock_all(timech, diech));
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
		{
			pthread_mutex_unlock(&(info->philoinfo)[countup].eat_ch);
			return (false);
		}
		pthread_mutex_unlock(&(info->philoinfo)[countup].eat_ch);
		countup++;
	}
	return (true);
}

bool	checker_end(t_allinfo *info, size_t philo_num, long long *d_t)
{
	pthread_mutex_lock(&(info->philoinfo)[philo_num].eat_ch);
	if ((info->philoinfo)[philo_num].correctend == false)
	{
		if (philo_deathistrue(&philo_num, info, d_t) == false)
		{
			pthread_mutex_unlock(&(info->philoinfo)[philo_num].eat_ch);
			return (false);
		}
	}
	pthread_mutex_unlock(&(info->philoinfo)[philo_num].eat_ch);
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
		if (checker_end(info, philo_num, &d_t) == false)
			return (NULL);
		philo_num++;
		if (philo_num == info->philo_num)
			philo_num = 0;
		usleep(200);
	}
	return (NULL);
}
