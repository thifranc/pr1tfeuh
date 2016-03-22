
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 15:35:36 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/21 10:37:21 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '%' && s[i])
		i++;
	return (i);
}

void	ft_putnb(long nb)
{
	if (0 <= nb && nb <= 9)
		ft_putchar(nb + 48);
	else
	{
		ft_putnb(nb / 10);
		ft_putnb(nb % 10);
	}
}

int		ft_count_opt(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i - 1] != '%' && s[i + 1] != '%')
			c++;
		i++;
	}
	return (c);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen((char*)s));
}

int		ft_arg_str(va_list va, char **str, int lol)
{
	char	*arg;

	arg = va_arg(va, char *);
	ft_putstr(arg);
	*str += 2;
	lol += 9;
	return (ft_strlen(arg));
}

int		ft_arg_nb(va_list va, char **str, int code)
{
	long	nb;
	int		c;

	if (code > 0)
	{
		if (code == 666)
			nb = va_arg(va, long);
		else
			nb = va_arg(va, unsigned int);
		ft_putnb(nb);
	}
	else
	{
		c = va_arg(va, int);
		ft_putchar(c);
	}
	*str += 2;
	return (0);
}

int		ft_printf(int nb, char *str, ...)
{
	int		i;
	int		flag;
	va_list	va;
	int		(*f[2])(va_list, char**, int);

	va_start(va, str);
	i = 0;
	f[0] = ft_arg_str;
	f[1] = ft_arg_nb;
	while (i < nb)
	{
		flag = 0;
		ft_putstr(str);
		str += ft_strlen(str);
		if ('1' <= *(str + 1) && *(str + 1) <= '9')
		{
			flag = *(str + 1) - 48;
			str++;
		}
		if (*(str + 1) == 's')
			flag = f[0](va, &str, 0);
		if (*(str + 1) == 'c')
			f[1](va, &str, 666);
		if (*(str + 1) == 'd')
			f[1](va, &str, 1);
		if (*(str + 1) == 'e')
			f[1](va, &str, -3);
		i++;
	}
	va_end(va);
	return (nb);
}

void	ft_print_memory(void *nb)
{
	int lol;

	lol = (int)nb;
	if (0 <= lol && lol <= 9)
		ft_putchar(lol + 48);
	else
	{
		ft_putnb(lol / 10);
		ft_putnb(lol % 10);
	}
}

int		main(void)
{
	int	nb_arg;
	int	*i;
	char	*lol;

	i = malloc(4);
	*i = 33;
	lol = "lol";
	nb_arg = ft_count_opt("% % % % % mes schalles%% %d");
	printf("%d ===== nb arg\n", nb_arg);
	ft_printf(nb_arg, "lol %e %c %s %d %s mes schalles %d", 97, 2147483655, "de", 83650, "et je mange", lol);
	printf("\n% -7.d||% d||%+d|||%-3.2s\n", 123, 433, 433, "lol");
	printf("%p\n", lol);
	return (0); 
}
