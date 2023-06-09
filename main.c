/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:07:02 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/14 18:07:02 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_allinfo	allinfo;

	if (ready_info(&allinfo, argc, argv) == false)
		return (1);
	if (constructer(&allinfo) == false)
		return (1);
	destructor(&allinfo);
	return (0);
}
