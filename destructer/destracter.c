/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destracter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:36:35 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/26 22:36:35 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	destructor(t_allinfo *info)
{
	mutex_destroy(info);
	destoroy_forks(info);
	destoroy_timech(info);
	destoroy_eatch(info);
	free(info->philoinfo);
	free(info->forks);
}
