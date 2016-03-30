/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:12:12 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/30 12:13:27 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_error(int flag, char *f)
{
	ft_put("\033[31musage : your [%] goes  with [#0-+ ] flags then length ");
	ft_put("and/or presicion then [hjzl] flags then converter\n\033[m");
	ft_put("usage is not respected due to : ");
	if (flag == 0)
		ft_put("flags '-' and '0' or flags '+' and ' '\n");
	if (flag == 1)
		ft_put("flags '+' or ' ' with an unsigned or a string converter\n");
	if (flag == 2)
		ft_put("flags '#' with something else than 'o' or 'x' converter\n");
	if (flag == 3)
		ft_put("length modifier with a string or a 'p' converter\n");
	if (flag == 4)
		ft_put("precision can't go with a char or wchar_t cenverter\n");
	if (flag == 5)
		ft_put("flags '0' can't go with string or a 'p' converter\n");
	if (flag == 6)
		ft_put("a precision can't be negative\n");
	if (flag == 7)
		ft_put("your length modifier flags isn't well put\n");
	if (flag == 8)
		ft_put("your converter flag isn't correct, RTFU ! (usage lol)\n");
	ft_put("\033[32mtry again !\n\033[m");
	exit(-1);
}

void	final_check(char *flag, int *tab)
{
	if (flag[2] && ft_get_char("DIdi%", flag[4]) == -1)
		ft_error(1, flag);
	if (flag[0] == '#' && ft_get_char("xXoO", flag[4]) == -1)
		ft_error(2, flag);
	if (ft_get_char("hHjz", flag[3]) != -1
		&& ft_get_char("psScC", flag[4]) != -1)
		ft_error(3, flag);
	if ((flag[4] == 'c' || flag[4] == 'C') && tab[1] != -1)
		ft_error(4, flag);
	if (flag[1] == '0' && (ft_get_char("psScC", flag[4]) != -1))
		ft_error(5, flag);
	if (ft_get_char("spdiouxcCSDOUX%", flag[4]) == -1)
		ft_error(8, flag);
}

void	ft_get_first_char(char **s, char *flag)
{
	while (**s && ft_get_char("#+- 0", **s) != -1)
	{
		if (**s == '#')
			flag[0] = '#';
		if ((**s == '0' && flag[1] == '-') || (**s == '-' && flag[1] == '0')
		|| (**s == '+' && flag[2] == ' ') || (**s == ' ' && flag[2] == '+'))
			ft_error(0, flag);
		if (**s == '0' && flag[1] != '-')
			flag[1] = **s;
		if (**s == '-' && flag[1] != '0')
			flag[1] = **s;
		if (**s == ' ')
			flag[2] = **s;
		if (**s == '+')
			flag[2] = **s;
		(*s)++;
	}
}

void	ft_get_last_char(char **s, char *flag)
{
	while (**s && ft_get_char("hjzl", **s) != -1)
	{
		if (ft_get_char("hjzl", **s) != -1 && flag[3])
			ft_error(7, flag);
		if (**s == *(*s + 1) && (**s == 'h' || **s == 'l'))
		{
			flag[3] = **s - 32;
			(*s)++;
		}
		else
			flag[3] = **s;
		(*s)++;
	}
	flag[4] = **s;
}

void	ft_get_opt(char **s, char *flag, int *tab)
{
	(*s)++;
	ft_get_first_char(s, flag);
	if ('1' <= **s && **s <= '9')
	{
		tab[0] = ft_atoi(*s);
		*s += ft_nb_len_base(tab[0], 10);
	}
	if (**s == '.')
	{
		if (*((*s) + 1) == '-')
			ft_error(6, flag);
		if ('0' <= *((*s) + 1) && *((*s) + 1) <= '9')
		{
			tab[1] = ft_atoi(*(s) + 1);
			*s += ft_nb_len_base(tab[1], 10) + 1;
		}
		else
			(*s)++;
	}
	else
		tab[1] = -1;
	ft_get_last_char(s, flag);
	(*s)++;
	final_check(flag, tab);
}
