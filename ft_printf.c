/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:13:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/25 10:43:56 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_clear_all(int *tab, char *flag, s_data s)
{
	int		i;

	i = -1;
	while (++i < 4)
		tab[i] = 0;
	i = -1;
	while (++i < 5)
		flag[i] = 0;
	s.s = NULL;
	s.c = 0;
	s.s_spe = NULL;
	s.c_spe = 0;
}

int		ft_strlen_char(const char *s, char b)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != b)
		i++;
	return (i);
}

int		ft_strcount(const char *s, char b)
{
	write(1, s, ft_strlen_char(s, b));
	return (ft_strlen_char(s, b));
}

int		ft_printf(char *str, ...)
{
	int			tab[4];
	char		f[5];
	s_data		s;
	va_list		va;

	va_start(va, str);
	s.c_spe = 0;
	s.s_spe = 0;
	s.s = 0;
	while (*str)
	{
		tab[3] += ft_strcount(str, '%');
		str += ft_strlen_char(str, '%');
		ft_clear_all(tab, f, s);//structure a clearer | attention appel function avec & ou non ?
		if (*(str + 1) == '%')
		{
			tab[3] += ft_strcount("%", '\0');
			str += 2;
		}
		else
		{
			ft_get_opt(str, f, tab);
			get_arg(va, f, tab, s);
		}
	}
	va_end(va);
	return (tab[3]);
}
