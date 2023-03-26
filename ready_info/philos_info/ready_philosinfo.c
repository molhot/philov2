/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_philosinfo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:51:36 by user              #+#    #+#             */
/*   Updated: 2023/03/26 19:53:58 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static	bool	philosmutex_init(t_allinfo *allinfo)
{
	if (pthread_mutex_init(&(allinfo->write), NULL) != 0)
	{
		mutex_error();
		return (false);
	}
	if (pthread_mutex_init(&(allinfo->diecheck), NULL) != 0)
	{
		pthread_mutex_destroy(&allinfo->write);
		mutex_error();
		return (false);
	}
	return (true);
}

static	bool	freereturn(t_allinfo *info)
{
	malloc_error();
	free_mutex(info);
	return (false);
}

static	bool	create_forks(t_allinfo *info)
{
	size_t	fork_num;

	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (info->forks == NULL)
	{
		mutex_destroy_component(info);
		return (freereturn(info));
	}
	fork_num = 0;
	while (fork_num != info->philo_num)
	{
		if (pthread_mutex_init(&info->forks[fork_num], NULL) != 0)
		{
			destoroy_forks_error(info, fork_num);
			return (freereturn(info));
		}
		fork_num++;
	}
	return (true);
}

bool	ready_philosinfo(t_allinfo *info, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->philo_die_ornot = false;
	if (philosmutex_init(info) == false)
		return (false);
	if (create_forks(info) == false)
		return (false);
	return (true);
}
