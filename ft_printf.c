/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:13:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/23 17:19:44 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_clear_all(int *tab, char *flag, s_struct *s)
{
	int		i;

	i = -1;
	while (++i < 4)
		tab[i] = 0;
	i = -1;
	while (++i < 5)
		flag[i] = 0;
	*s.s = NULL;
	*s.s_spe = NULL;
	*s.c_spe = 0;
}

int		ft_strlen_char(char *s, char b)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != b)
		i++;
	return (i);
}

int		ft_strcount(char *s, char b)
{
	write(1, s, ft_strlen_char(s, b));
	return (ft_strlen_char(s, b));
}

int		ft_printf(char *str, ...)
{
	int			tab[4];
	char		f[5];
	s_struct	s;
	va_list		va;

	va_start(va, str);
	while (*str)
	{
		tab[3] += ft_strcount(str, '%');
		str += ft_strlen_char(str, '%');
		ft_clear_all(tab, f, &s);//structure a clearer ?
		if (*(str + i) == '%')
		{
			tab[3] += ft_strcount("%", '\0');
			str += 2;
		}
		else
		{
			ft_get_opt(str, flag, tab);
			get_arg(va, flag, tab, &s);
		}
	}
	va_end(va);
	return (tab[3]);
}
