/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:12:12 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/28 17:04:53 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_error(int flag, char *f)
{
	printf("ERROR CALLED for f == %c|%c|%c|%c|%c\n", f[0], f[1], f[2], f[3], f[4]);
	if (flag == 0)
		printf("qui c'est qui melange les carottes et les choux ta race ?\n");
	if (flag == 1)
		printf("pas de '-' ou de '+' avec des unsigned ou des phrases steuplait\n");
	if (flag == 2)
		printf("wesh en fait les '#' ca passe que si tu mets un 'x' un 'X' un 'o' ou un 'O' mec\n");
	if (flag == 3)
		printf("vas y mets pas de modif de longueur avec les convertisseurs sSpcC c'est deja assez galere");
	if (flag == 4)
		printf("lol de mettre une precision avec un c, y a QUE UN TRUC A ECRIRE QU'EST-CE TU FAIS CHIER");
	if (flag == 5)
		printf("je vais pas ecrire des zero devant des phrases t'es con ou quoi ?");
	if (flag == 6)
		printf("lol t'as voulu jouer ton malin avec une precision negative et bah ca degage !");
	if (flag == 7)
		printf("pas de doublons ds les flags steuplait. al la limite hh et ll j'accepte mais c'est tout");
	exit(-1);
}

int		final_check(char *flag, int *tab)
{
	if ((flag[2] == '-' || flag[2] == '+') && ft_get_char("DIdi", flag[4]) == -1)
		return (ft_error(1, flag));
	if (flag[0] == '#' && ft_get_char("xXoO", flag[4]) == -1)
		return (ft_error(2, flag));
	if (ft_get_char("hHjz", flag[3]) != -1 && ft_get_char("psScC", flag[4]) != -1)
	{
		printf("%d = retour get char hHjz && %d retour autre ft\n", ft_get_char("hHjz", flag[3]), ft_get_char("psScC", flag[4]));
		printf("%c == flag[3] &&&& %c === flag[4]\n", flag[3], flag[4]);
		return (ft_error(3, flag));
	}
	if (ft_get_char("sScCpouxOUX", flag[4]) != -1 && flag[2])
		return (0);
	if ((flag[4] == 'c' || flag[4] == 'C') && tab[1] != -1)
		return (ft_error(4, flag));
	if (flag[1] == '0' && (ft_get_char("psScC", flag[4]) != -1))
		return (ft_error(5, flag));
	return (1);
}

int		ft_get_first_char(char **s, char *flag)
{
	while (**s && ft_get_char("#+- 0", **s) != -1)
	{
		if (**s == '#')
			flag[0] = '#';
		if ((**s == '0' && flag[1] == '-') || (**s == '-' && flag[1] == '0')
				|| (**s == '+' && flag[2] == ' ') || (**s == ' ' && flag[2] == '+'))
			return (ft_error(0, flag));
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
		if (ft_get_char("hjzl", **s) != -1 && flag[3])
			return (ft_error(7, flag));
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
	return (1);
}

int		ft_get_opt(char **s, char *flag, int *tab)
{
	if (!ft_get_first_char(s, flag))
		return (0);
	if ('1' <= **s && **s <= '9')
	{
		tab[0] = ft_atoi(*s);
		*s += ft_nb_len_base(tab[0], 10);
	}
	printf("%c = la ou jsuis |||| %d = atoi\n", **s, tab[0]);
	if (**s == '.')
	{
		if (*((*s) + 1) == '-')
			return (ft_error(6, flag));
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
	if (!ft_get_last_char(s, flag))
		return (0);
	(*s)++;
	return (final_check(flag, tab));
}
