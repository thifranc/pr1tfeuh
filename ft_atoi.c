/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 11:52:58 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/28 17:50:22 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_atoi(char *str)
{
	int flag;
	int nb;
	int tmp;

	nb = 0;
	flag = 0;
	while (*str && (*str == '\t' || *str == '\n' || *str == ' '
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		flag = 1;
	if (*str == '-' || *str == '+')
		str++;
	while ('0' <= *str && *str <= '9' && *str)
	{
		tmp = *str - 48;
		nb = nb * 10 + tmp;
		str++;
	}
	if (flag == 1)
		nb = -nb;
	return (nb);
}
