/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wrd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:57:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/25 12:45:53 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//RESTE PROBLEME DE RETOUR DE FONCTION CF MAIN_TEST SINON TOUT ROULE

#include "libftprintf.h"

void	do_wrd(char *flag, int *tab, s_data s)
{
	int		max_char;

	max_char = get_max_char(s, tab);
	if (!flag[1])
		ft_print_n_char(' ', tab[0] - max_char);
	if (s.c_spe)//gerer debut de arg
		ft_putwchar(s.c_spe);
	else if (s.s_spe)
		ft_putwstr(s.s_spe, max_char);
	else if (s.s)
		ft_putstr(s.s, max_char);
	else // (s.c)
		ft_putchar(s.c);
	tab[3] += max_char > tab[0] ? max_char : tab[0];//modifier appels fonctions;
	if (flag[1] == '-')
		ft_print_n_char(' ', tab[0] - max_char);
}

int		get_max_char(s_data s, int *tab)
{
	int	max_char;

	max_char = 0;
	if (s.s)
		max_char = ft_strlen(s.s);
	else if (s.s_spe)
		max_char = ft_wstrlen(s.s_spe);
	else if (s.c)
		max_char = 1;
	else //(s.c_spe)
	{
		if (s.c_spe <= 0x7F)
			max_char = 1;
		else if (s.c_spe <= 0x7FF)
			max_char = 2;
		else if (s.c_spe <= 0xFFFF)
			max_char = 3;
		else
			max_char = 4;
	}
	if (tab[1] >= 0)
		return (max_char > tab[1] ? tab[1] : max_char);
	else
		return (max_char);
}

int		ft_wstrlen(wchar_t *str)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			ct += 1;
		else if (str[i] <= 0x7FF)
			ct += 2;
		else if (str[i] <= 0xFFFF)
			ct += 3;
		else // (str[i] <= 0x1FFFFF)
			ct += 4;
		i++;
	}
	printf("%d == length\n", ct);
	return (ct);
}

void	ft_putwstr(wchar_t *str, int ct)
{
	int	i;

	i = 0;
	while (str[i] && ct > 0)
	{
		if (str[i] <= 0x7F)
			ct -= 1;
		else if (str[i] <= 0x7FF)
			ct -= 2;
		else if (str[i] <= 0xFFFF)
			ct -= 3;
		else // (str[i] <= 0x1FFFFF)
			ct -= 4;
		if (ct > 0)
			ft_putwchar(str[i]);
		i++;
	}
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
		mask = 256 - ft_power(2, (7 - max));
		cpy = (cpy >> (max * 6) | mask);
		write(1, &cpy, 1);
		while (max)//remplacer par --(max + 1)?
		{
			cpy = (int)c >> (6 * (max - 1));
			cpy = (cpy & 63) | 128;
			write(1, &cpy, 1);
			max--;
		}
	}
}
