/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_philoinfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:23:28 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/14 19:23:28 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static	bool	insert_info_tophilo(int philonum, \
t_allinfo *info, char **argv, int argc)
{
	((info->philoinfo)[philonum - 1]).fork_info.r_fork = philonum - 2;
	((info->philoinfo)[philonum - 1]).fork_info.l_fork = philonum - 1;
	((info->philoinfo)[philonum - 1]).how_eated = 0;
	((info->philoinfo)[philonum - 1]).number_of_philo = philonum;
	((info->philoinfo)[philonum - 1]).correctend = false;
	if (argc == 6)
		((info->philoinfo)[philonum - 1]).eat_limit = ft_atoi(argv[5]);
	else
		((info->philoinfo)[philonum - 1]).eat_limit = -1;
	((info->philoinfo)[philonum - 1]).all_info = info;
	((info->philoinfo)[philonum - 1]).time_to_eat = ft_atoi(argv[3]);
	((info->philoinfo)[philonum - 1]).time_to_sleep = ft_atoi(argv[4]);
	((info->philoinfo)[philonum - 1]).time_to_die = ft_atoi(argv[2]);
	((info->philoinfo)[philonum - 1]).time_to_think = 0;
	if (pthread_mutex_init(&(((info->philoinfo)[philonum - \
	1]).timecheck_same), NULL) != 0)
		return (destoroy_timech_error(info, philonum));
	if (pthread_mutex_init(&(((info->philoinfo)[philonum - \
	1]).eat_ch), NULL) != 0)
	{
		destoroy_timech(info);
		return (destoroy_eatch_error(info, philonum));
	}
	return (true);
}

bool	create_samephilo(t_allinfo *info, char **argv, int argc)
{
	size_t	l_f_n;

	l_f_n = 1;
	info->philoinfo = (t_philo *)malloc(sizeof(t_philo) * info->philo_num);
	if (info->philoinfo == NULL)
	{
		malloc_error();
		return (false);
	}
	while (l_f_n != info->philo_num + 1)
	{
		if (insert_info_tophilo(l_f_n, info, argv, argc) == false)
			return (false);
		l_f_n++;
	}
	((info->philoinfo)[0]).fork_info.r_fork = 0;
	((info->philoinfo)[0]).fork_info.l_fork = info->philo_num - 1;
	return (true);
}
