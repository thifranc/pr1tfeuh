/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_len_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:10:29 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/28 17:05:51 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_nb_len_base(long long int n, int base)
{
	if (0 <= n && n < base)
		return (1);
	else
		return (1 + ft_nb_len_base(n / base, base));
}
