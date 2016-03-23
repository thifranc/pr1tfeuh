#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

int		ft_power(int a, int b);
int		ft_nb_len_base(int nb, int base);

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
			cpy = (int)c >> (6 * (max - 1));//PROBLEME
			cpy = (cpy & 63) | 128;
			write(1, &cpy, 1);
			max--;
		}
	}
}

void	putwstr(wchar_t *lol)
{
	int	i;

	i = 0;
	while (lol[i])
	{
		ft_putwchar(lol[i]);
		i++;
	}
}

int		main()
{
	char* l = setlocale(LC_ALL, "");
	if (l == NULL)
		printf("locale not set\n");
	else
		printf("set %s\n", l);
	printf("\n%07d\n", 33);
	printf("%07.d\n", 33);
	putwstr(L"滑石不生苔) 常改行是发不了财的\n");
	putwstr(L"لاتنفق كلمتين اذا كفتك كلمة ـ مثل عربي");
	printf("%p\n", l);
	printf("%22p", l);

	return (0);
}

/*
 * test de batard :
 * diff
 * +07d, 33
 * +07.d, 33
 * mettre une precision negative
 * h ac s
 * + ou ' ' ac un unsigned
 * */
