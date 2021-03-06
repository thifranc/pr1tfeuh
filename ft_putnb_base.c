/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:53:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/31 10:51:44 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnb_base(long long int n, char *base)
{
	if (n == -9223372036854775807 - 1)
		ft_put("-9223372036854775808");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnb_base(-n, base);
	}
	else if (0 <= n && n < ft_strlen(base))
		ft_putchar(base[n]);
	else
	{
		ft_putnb_base(n / ft_strlen(base), base);
		ft_putnb_base(n % ft_strlen(base), base);
	}
}
