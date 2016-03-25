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
			ct +=4;
		i++;
	}
	return (ct);
}

void	putwstr(wchar_t *lol)
{
	int	i;

	i = 0;
	while (lol[i])
	{
		ft_putwchar(lol[i]);
/*		if (str[i] <= 0x7F)
			ct -= 1;
		else if (str[i] <= 0x7FF)
			ct -= 2;
		else if (str[i] <= 0xFFFF)
			ct -= 3;
		else // (str[i] <= 0x1FFFFF)
			ct -=4;*/
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
	ft_putwchar(45454);
	putwstr(L"\n滑石不生苔) 常改行是发不了财的\n");
	putwstr(L"لاتنفق كلمتين اذا كفتك كلمة ـ مثل عربي\n");
	putwstr(L"宜しく/どうぞ宜しく/どうぞ宜しくお願いします。\n");
	putwstr(L"Ευχαριστώ για την βοήθεια\n");
	putwstr(L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ\n");
	printf("%d ====RETOUR FONCTION PRINTF\n", printf("%ls", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ\n"));
	printf("%p\n", l);
	printf("%22p\n", l);
	printf("%d ======= STRLEN\n", ft_wstrlen(L"宜しく/ど"));
	printf("%d = strlen &RETOUR FONCTION == %d \n", ft_wstrlen(L"宜しく/ど"), printf("%ls", L"宜しく/ど"));
	printf("%#0.12x\n", 12345);
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
