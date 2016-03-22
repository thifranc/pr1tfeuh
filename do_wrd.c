/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wrd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:57:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/22 14:11:50 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_wrd(char *flag, int *tab, struct s_letter)
{
	if (s_letter.wlet)
		ft_putwchar(s_letter.wlet);
	else if (s_letter.wstr)
		ft_putwstr(s_letter.wlet);
	else if (s_letter.str)
		ft_strcount(s_letter.str);
}

int		ft_strcount(char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}

int		ft_putwstr(wchar_t *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_putwchar(wchar_t c)
{
	int		cpy;
	int		len;
	int		max;
	int		mask;

	cpy = (int)c;
	len = ft_nb_len_base(cpy, 2);
	if (len <= 7)
		write(1, &c, 1);
	else 
	{
		max = len > 11 ? 2 : 1;
		max += len > 16 ? 1 : 0;
		mask = 256 - ft_power(2, (8 - max));
		(cpy >> len - (len - 6) | mask);
		write(1, &cpy, 1);
		while (max)
		{
			cpy = (int)c >> (6 * max);
			((cpy << (len - 6)) >> (len - 6) | 128);
			write(1, &cpy, 1);
			max--;
		}
	}
}
