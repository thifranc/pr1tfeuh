/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wrd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:57:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/29 19:58:22 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//RESTE PROBLEME DE RETOUR DE FONCTION CF MAIN_TEST SINON TOUT ROULE

#include "libftprintf.h"

void	do_wrd(char *flag, int *tab, t_data s)
{
	int		max_char;

	max_char = get_max_char(s, tab, flag);
	if (!flag[1])
		ft_print_n_char(' ', tab[0] - max_char);
	if (flag[4] == 's' && !flag[3])
		ft_putstr(s.s, max_char);
	else if (flag[4] == 'c' && !flag[3])
		ft_putchar(s.c);
	else if (flag[4] == 'S' || (flag[3] == 'l' && flag[4] == 's'))
		ft_putwstr(s.s_spe, max_char);
	else // (s.c)
		ft_putwchar(s.c_spe);
	tab[3] += max_char > tab[0] ? max_char : tab[0];
	if (flag[1] == '-')
		ft_print_n_char(' ', tab[0] - max_char);
}

int		get_max_char(t_data s, int *tab, char *flag)
{
	int	max;

	max = 0;
	if (flag[4] == 's' && !flag[3])
		max = ft_strlen(s.s);
	else if (flag[4] == 'S' || (flag[3] == 'l' && flag[4] == 's'))
		max = ft_wstrlen(s.s_spe, tab[1]);
	else if (flag[4] == 'c' && !flag[3])
		max = 1;
	else //(s.c_spe)
	{
		if (s.c_spe <= 0x7F)
			max = 1;
		else if (s.c_spe <= 0x7FF)
			max = 2;
		else if (s.c_spe <= 0xFFFF)
			max = 3;
		else
			max = 4;
	}
	if (tab[1] >= 0)
		return (max > tab[1] ? tab[1] : max);
	else
		return (max);
}

int		ft_wstrlen(wchar_t *str, int max)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (str[i])
	{
		if (ct + 1 <= max && str[i] <= 0x7F)
			ct += 1;
		else if (ct + 2 <= max && str[i] <= 0x7FF)
			ct += 2;
		else if (ct + 3 <= max && str[i] <= 0xFFFF)
			ct += 3;
		else // (str[i] <= 0x1FFFFF)
			if (ct + 4 <= max)
				ct += 4;
		i++;
	}
	return (ct);
}

void	ft_putwstr(wchar_t *str, int ct)
{
	int	i;

	i = 0;
	while (str[i] && ct >= 0)
	{
		if (str[i] <= 0x7F)
			ct -= 1;
		else if (str[i] <= 0x7FF)
			ct -= 2;
		else if (str[i] <= 0xFFFF)
			ct -= 3;
		else // (str[i] <= 0x1FFFFF)
			ct -= 4;
		if (ct >= 0)
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
		write(1, &c, 1);
	else
	{
		max = len > 11 ? 2 : 1;
		max += len > 16 ? 1 : 0;
		mask = 256 - ft_power(2, (7 - max));
		cpy = (cpy >> (max * 6) | mask);
		write(1, &cpy, 1);
		while (max)
		{
			cpy = (int)c >> (6 * (max - 1));
			cpy = (cpy & 63) | 128;
			write(1, &cpy, 1);
			max--;
		}
	}
}
