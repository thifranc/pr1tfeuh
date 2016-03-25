/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_nb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 09:03:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/25 10:41:29 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//CETTE PAGE EST AVLIDEE POUR LA PLUPART DES CAS MAIS PEUT ETRE PAS 100% DES CAS FURENT TESTES
#include "libftprintf.h"

/*
 *RESTE A FAIRE
les cas d'erreurs
 * */

int		get_total_char(long long int arg, char *flag, int *tab)
{
	int		tmp;

	if (flag[4] == 'x' || flag[4] == 'X' || flag[4] == 'p')
		tab[2] = 16;
	else if (flag[4] == 'o')
		tab[2] = 8;
	else
		tab[2] = 10;
	tmp = ft_nb_len_base(arg, tab[2]);
	if ((flag[0] == '#' && (flag[4] == 'o' || flag[4] == 'O')) || flag[2] != '\0')
		tmp++;
	if ((flag[0] == '#' && (flag[4] == 'x' || flag[4] == 'X')) || flag[4] == 'p')
		tmp += 2;
	return (tmp);
}

void	print_beg(char *flag, int *tab, int max_char, long long int arg)
{
	if ((!flag[1] || (flag[1] == '0' && tab[1] >= 0/*dc cas ou tab[1] != -1*/)) /*&& tab[0] > max_char*/)
		ft_print_n_char(' ', tab[0] - max_char);//verif inutile tab[0] > max_char car si < print pas
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
	tab[3] += (max_char > tab[0]) ? max_char : tab[0];// ici tab[3] incremente
	print_beg(flag, tab, max_char, arg);
	if (flag[0] == '#' && (flag[4] == 'X' || flag[4] == 'p' || flag[4] == 'x'))
		flag[4] == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	if (tab[2] == 16 && flag[4] == 'X')
		tab[2] = 1;
	ft_get_code(tab[2], arg);
	if (flag[1] == '-')
		ft_print_n_char(' ', tab[0] - max_char);
}

void	ft_get_code(int base, long long int arg)
{
	char	*out;

	if (base == 1)
		out = ft_strdup("0123456789ABCDEF");
	else
	{
		out = ft_strdup("0123456789abcdefghijklmonpqrstuvwxyz");
		out[base] = '\0';
	}
	ft_putnb_base(arg, out);
	free(out);
}
