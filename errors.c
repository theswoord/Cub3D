/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:02 by nbouhali          #+#    #+#             */
/*   Updated: 2024/01/30 16:49:58 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		int ret = write(2, &str[i], 1);
		i++;
	}
}

void	problem(char *str)
{
	print_error(str);
	exit(1);
}
