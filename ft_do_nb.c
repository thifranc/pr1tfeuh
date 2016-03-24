/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_nb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 09:03:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/24 14:24:10 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 *RESTE A FAIRE
LE MAIN (+- = FT_PRINTF DEJA EXISTANT)
TOUT LE DEBUG MAIS INSHA ALLH Y  PAS BCP
MAKEFILE + LIBFTPRINTF.H
preparer options + string
 * */

int		get_total_char(long long int arg, char *flag, int *tab)
{
	int		out;
	int		tmp;

	if (flag[4] == 'x' || flag[4] == 'X' || flag[4] == 'p')
		tab[2] = 16;
	else if (flag[4] == 'o')
		tab[2] = 8;
	else
		tab[2] = 10;
	tmp = ft_nb_len_base(arg, tab[2]);
	out = (tmp > tab[0]) ? tmp : tab[0];
	if ((flag[0] == '#' && (flag[4] == 'o' || flag[4] == 'O')) || flag[2] != '\0')
		out++;
	if ((flag[0] == '#' && (flag[4] == 'x' || flag[4] == 'X')) || flag[4] == 'p')
		out += 2;
	return (out);
}

void	print_beg(char *flag, int *tab, int max_char, long long int arg)
{
	if ((!flag[1] || (flag[1] == '0' && tab[1] >= 0/*dc cas ou tab[1] != -1*/)) /*&& tab[0] > max_char*/)
		ft_print_n_char(' ', tab[0] - max_char);//verif inutile tab[0] > max_char car si < print pas
	write(1, &flag[2], 1);
	if (flag[1] == '-')
		ft_print_n_char(' ', tab[1] - ft_nb_len_base(arg, tab[2]));
	if (flag[2] != '\0')
		write(1, &flag[2], 1);
	ft_print_n_char('0', tab[1] - ft_nb_len_base(arg, tab[2]));
}

void	do_nb(char *flag, int *tab, long long int arg)
{
	int		max_char;

	max_char = get_total_char(arg, flag, tab);
	tab[3] += max_char;// ici tab[3] incremente
	print_beg(flag, tab, max_char, arg);
	flag[4] == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	if (tab[2] == 16 && flag[4] == 'X')
		tab[2] = 1;
	ft_putnb_base(arg, ft_get_code(tab[2]));
	if (flag[1] == '-')
		ft_print_n_char(' ', tab[0] - max_char);
}

char	*ft_get_code(int base)
{
	char	*out;

	if (base == 1)
		return ("0123456789ABCDEF");
	out = "0123456789abcdefghijklmonpqrstuvwxyz";
	out[base] = '\0';
	return (out);
}
