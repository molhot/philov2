/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:31:16 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/26 22:31:16 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

bool	unlock_all(pthread_mutex_t *timech, pthread_mutex_t *diech)
{
	pthread_mutex_unlock(timech);
	pthread_mutex_unlock(diech);
	return (false);
}

bool	not_death(pthread_mutex_t *timech)
{
	pthread_mutex_unlock(timech);
	return (true);
}
