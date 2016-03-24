/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:12:12 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/24 16:41:11 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_get_first_char(char **s, char *flag)
{
	while (**s && ft_get_char("#+- 0", **s) != -1)//pb correspondance ** et *
	{
		if (**s == '#')
			flag[0] = '#';
		if ((**s == '0' && flag[1] == '-') || (**s == '-' && flag[1] == '0')
		|| (**s == '+' && flag[2] == ' ') || (**s == ' ' && flag[2] == '+'))
			return (0);
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
	return (1);
}

int		ft_get_last_char(char **s, char *flag)
{
	while (**s && ft_get_char("hjzl", **s) != -1)
	{
		if (ft_get_char("hjzl", **s) != -1 && flag[3])//eq a flag[3] != '\0'
			return (0);
		if (**s == *(*s + 1) && (**s == 'h' || **s == 'l'))//protection autre doublons
		{
			flag[3] = **s - 32;
			(*s)++;
		}
		else
			flag[3] = **s;
		(*s)++;
	}
	flag[4] = **s;//charge cvtisseur
	return (1);
}

int		final_check(char *flag)
{
	if ((flag[2] == '-' || flag[2] == '+') && ft_get_char("DIdi", flag[2]) == -1)
		return (0);
	if (flag[0] == '#' && ft_get_char("xXo", '#') == -1)
		return (0);
	if (ft_get_char("hHjz", flag[3]) != -1 && ft_get_char("psScC", flag[4]) != -1)
		return (0);
	if (ft_get_char("ouxOUX", flag[4]) != -1 && (flag[2] == ' ' || flag[2] == '+'))//if flag[2] existe
		return (0);
	return (1);
	//autres tests a faire genre h et s etc
	//x et + pas ensembles (surement + et les unsigned)
	//'p' et ' ' pas ensembles
	//%s que ac '-' et les tab ok
	//%c non ac precision
}

int		ft_error(void)
{
	ft_putstr("ic'est qui qui sait pas lire l'usage bordel\n");
	return (0);
}

int		ft_get_opt(char *s, char *flag, int *tab)//recoit tab et flag car le main les clear
{
	printf("JJJJJJJJJJJJJJJEEEEEEEEEEEEEEEEEEEEEEEE T  AAIIIIIIIIIIIMMMMMMMMMMMEEEEEEEEEEEE");
	if (!ft_get_first_char(&s, flag))
		return (0);//ERROR
	if ('1' <= *s && *s <= '9')
	{
		tab[0] = ft_atoi(s);
		s += ft_nb_len_base(tab[0], 10);
	}
	if (*s == '.')
	{
		if (*(s + 1) == '-')
			return (0);//ERROR
		if ('0' <= *(s + 1) && *(s + 1) <= '9')
		{
			tab[1] = ft_atoi(s + 1);
			s += ft_nb_len_base(tab[1], 10) + 1;
		}
		else
			s++;
	}//attention ! difference entre pas de precision et precision = 0 si pas prec : tab[1] == -1
	else
		tab[1] = -1;
	if (!ft_get_last_char(&s, flag))
		return (0);//ERROR
	return (final_check(flag));
}
