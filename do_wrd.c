/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wrd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:57:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/23 17:17:06 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_wrd(char *flag, int *tab, s_struct s)
{
	if (s.c_spe)
		tab[3] += ft_putwchar(s.c_spe);
	else if (s.s_spe)
		tab[3] += ft_putwstr(s.s_spe);
	else if (s.s)
		tab[3] += ft_strcount(s.s, '\0');
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
		write(1, &c, 1);//pb si char == 200 nan c bon y a unicode pas ascii
	else 
	{
		max = len > 11 ? 2 : 1;
		max += len > 16 ? 1 : 0;
		mask = 256 - ft_power(2, (8 - max));
		(cpy >> len - (len - 6) | mask);
		write(1, &cpy, 1);
		while (max)
		{
			cpy = (int)c >> (6 * (max - 1));
			cpy = (cpy & 63) | 128;
			write(1, &cpy, 1);
			max--;
		}
	}
	return (1);
}
