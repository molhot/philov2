/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_eatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:04:18 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/26 20:04:18 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

bool	destoroy_eatch_error(t_allinfo *info, size_t i)
{
	size_t	pn;

	pn = 1;
	while (pn != i)
	{
		pthread_mutex_destroy(
			&(((info->philoinfo)[pn - 1]).eat_ch));
		pn++;
	}
	return (false);
}

void	destoroy_eatch(t_allinfo *info)
{
	size_t	pn;
	size_t	all_pn;

	pn = 1;
	all_pn = info->philo_num + 1;
	while (pn != all_pn)
	{
		pthread_mutex_destroy(
			&(((info->philoinfo)[pn - 1]).eat_ch));
		pn++;
	}
}
