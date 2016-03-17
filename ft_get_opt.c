/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:12:12 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/16 10:58:05 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_opt_char(char **s, char **flag, char *f, int option)
{
	if (option == 1)
	{
		while (**s && ft_get_char(f, **s) != -1)//pb correspondance ** et *
		{//if %########s printf marche dc ok
			if (**s == '#')
				*flag[0] = '#';
			if (**s == '0' || **s == '-')
				*flag[1] = **s;
			if (**s == '+' || **s == ' ')
				*flag[2] = **s;
			(*s)++;
		}
	}
	else
		while (**s && ft_get_char(f, **s) != -1)
		{
			if (**s == *(*s + 1) && (**s == 'h' || **s == 'l'))//protection
			{
				*flag[3] = **s - 32;
				(*s)++;
			}
			else
				*flag[3] = **s;
			(*s)++;
		}
}

int		ft_double(char *s, char *code)
{
	int		i;
	char	back[2];

	i = 0;
	ft_bzero(back, 2);
	while (s[i] != '.' && ft_get_char(code, s[i]) == -1)
	{
		if ((s[i] == '0' || s[i] == '-') && back[0])
			return (1);
		if ((s[i] == '0' || s[i] == '-') && !back[0])
			back[0] = s[i];
		if ((s[i] == ' ' || s[i] == '+') && back[1])
			return (1);
		if ((s[i] == ' ' || s[i] == '+') && !back[1])
			back[1] = s[i];
		i++;
	}
	return (0);
}

int		ft_error(void)
{
	ft_putstr("erreur allez on lache rien tu vas le nik le prog\n");
	return (0);
}

int		ft_get_opt(char *s, char *flag, int *tab)//ft_error exsite pas
{
	if (ft_double(s, "hljzsSpdDioOuUxXcC") == 1)
		return (ft_error());
	ft_get_opt_char(&s, &flag, "#0- +", 1);
	if (!*s)
		return (ft_error());
	if ('1' <= *s && *s <= '9')
	{
		tab[0] = ft_atoi(s);
		s += ft_nb_len_base(tab[0], 10);
	}
	if (*s == '.' && '0' <= *(s + 1) && *(s + 1) <= '9')
	{
		tab[1] = ft_atoi(s + 1);
		s += ft_nb_len_base(tab[1], 10) + 1;
	}
	if (*s == '.')
		s++;
	ft_get_opt_char(&s, &flag, "hljzsSpdDioOuUxXcC", 2);
	if (!*s)
		return (ft_error());
	flag[4] = *s;
	return (1);
}
