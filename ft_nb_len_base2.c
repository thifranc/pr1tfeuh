/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_len_base2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:10:29 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/06 10:05:30 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_nb_len_base2(unsigned long long int n, int base)
{
	if (n < (unsigned long long int)base)
		return (1);
	else
		return (1 + ft_nb_len_base2(n / base, base));
}
