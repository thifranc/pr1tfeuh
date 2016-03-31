/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_base2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:53:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/31 10:30:01 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnb_base2(unsigned long long int n, char *base)
{
	if (n < ft_strlen(base))
		ft_putchar(base[n]);
	else
	{
		ft_putnb_base2(n / ft_strlen(base), base);
		ft_putnb_base2(n % ft_strlen(base), base);
	}
}
