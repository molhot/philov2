/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:54:22 by user              #+#    #+#             */
/*   Updated: 2023/03/23 13:19:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philolife_life(void *info_t)
{
	t_philo			*info;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;

	info = (t_philo *)info_t;
	lf = &(info->all_info->forks[info->fork_info.l_fork]);
	rf = &(info->all_info->forks[info->fork_info.r_fork]);
	if (info->number_of_philo == info->all_info->philo_num && info->all_info->philo_num % 2 == 1)
		usleep(200);
	livestart_ch(info);
	while (1)
	{
		if (eat_drop(info, lf, rf, info->number_of_philo) == false)
			return (NULL);
		if (info->eat_limit != -1 && info->eat_limit <= (int)info->how_eated)
			break ;
		if (sleeping(info) == false)
			return (NULL);
	}
	info->correctend = true;
	return (NULL);
}
