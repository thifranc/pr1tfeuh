#include "libftprintf.h"
#include <wchar.h>
#include <stdio.h>
#include <locale.h>
//segfault if %s et arg = int
int		main(void)
{
	char* l = setlocale(LC_ALL, "");
	if (l == NULL)
		printf("locale not set\n");
	else
		printf("set %s\n", l);

	char	*ptr;
	char	lol;
	unsigned long t;
	int	a;
	int	b;

	t = -42;

	lol = 'h';
	ptr = &lol;
	//test batard
	ft_printf("\ntest option debut :\n\n");
	a = printf("\033[32mref==>%+07d\n\033[0m", 33);
	printf("\033[32mref==>%+07.d\n\033[0m", 33);
	printf("resultat de ma fonction : \n");
	b = ft_printf("\033[33mmoi==>\033[0m%+07d\n", 33);
	ft_printf("\033[33mmoi==>\033[0m%+07.d\n", 33);
	printf("a == %d ||| b == %d\n", a, b);

	//test option '-'
	printf("\nnouveau test option\n\n");
	a = printf("\033[32mref==>%-dfin\n\033[0m", 33);
	printf("\033[32mref==>% 9dfin\n\033[0m", 33);
	printf("resultat de ma fonction : \n");
	b = ft_printf("\033[33mmoi==>\033[0m%-dfin\n", 33);
	ft_printf("\033[33mmoi==>\033[0m% 9dfin\n", 33);
	printf("a == %d ||| b == %d\n", a, b);

	//test option '#'
	printf("\n nouveau test\n\n");
	a = printf("\033[32mref==>%#011xfin\n\033[0m", 33);
	printf("resultat de ma fonction : \n");
	b = ft_printf("\033[33mmoi==>\033[0m%#011xfin\n", 33);
	printf("a == %d ||| b == %d\n", a, b);

	//test option modif longueur
	printf("\n nouveau test\n\n");
	a = printf("\033[32mref==>%15ldfin\n\033[0m", 2147364765555);
	printf("resultat de ma fonction : \n");
	b = ft_printf("\033[33mmoi==>\033[0m%15ldfin\n", 2147364765555);
	printf("a == %d ||| b == %d\n", a, b);

	// test option 'p'
	printf("\n nouveau test\n\n");
	a = printf("\033[32mref==>%-23pfin\n\033[0m", ptr);
	printf("resultat de ma fonction : \n");
	b = ft_printf("\033[33mmoi==>\033[0m%-23pfin\n", ptr);
	printf("a == %d ||| b == %d\n", a, b);

	//test option max string
	printf("\n nouveau test\n\n");
	a = printf("\033[32mref==>%.22lsfin\n\033[0m", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ");
	printf("resultat de ma fonction : \n");
	b = ft_printf("\033[33mmoi==>\033[0m%.22Sfin\n", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ");
	printf("a == %d ||| b == %d\n", a, b);

	//retour ft
	printf("\n nouveau test\n\n");
	printf("\033[32m  ret ft ==>%d\n\033[m", printf("%.23lsfin", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ"));
	printf("resultat de ma fonction : \n");
	ft_printf("\033[33m  ret ft ==>%d\n\033[m", ft_printf("%.23Sfin", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ"));
	
	//test conv unsigned
	printf("\n nouveau test\n\n");
	a = printf("\033[32mref==>%ufin\n\033[0m", (unsigned)-42);
	printf("resultat de ma fonction : \n");
	b = ft_printf("\033[33mmoi==>\033[0m%ufin\n", -42);
	ft_printf("\033[33mmoi==>\033[0m%ufin\n", t);
	printf("a == %d ||| b == %d\n", a, b);

	//test conv long unsigned
	printf("\n nouveau test\n\n");
	a = printf("\033[32mref==>%lufin\n\033[0m", (long unsigned)-42);
	printf("resultat de ma fonction : \n");
	b = ft_printf("\033[33mmoi==>\033[0m%lufin\n", (long unsigned)-42);
	ft_printf("\033[33mmoi==>\033[0m%lufin\n", (unsigned long)t);
	printf("a == %d ||| b == %d\n", a, b);

	//test %
	printf("\n nouveau test pour %%%%\n\n");
	a = printf("\033[32mref==>%.22%fin\n\033[0m");
	printf("\033[32mref==>%6.2%fin\n\033[0m");
	printf("\033[32mref==>%09.8%fin\n\033[0m");
	printf("\033[32mref==>%-9.3%fin\n\033[0m");
	printf("resultat de ma fonction : \n");
	b = ft_printf("\033[33mmoi==>%.22%fin\n\033[0m");
	ft_printf("\033[33mmoi==>%6.2%fin\n\033[0m");
	ft_printf("\033[33mmoi==>%09.8%fin\n\033[0m");
	ft_printf("\033[33mmoi==>%-9.3%fin\n\033[0m");
	printf("a == %d ||| b == %d\n", a, b);

	//test null
	printf("\n nouveau test\n\n");
	a = printf("\033[32mref==>%sfin\n\033[0m", NULL);
	printf("\033[32mref==>%cfin\n\033[0m", 0);
	printf("resultat de ma fonction : \n");
	b = ft_printf("\033[33mmoi==>\033[0m%sfin\n", NULL);
	ft_printf("\033[33mmoi==>\033[0m%cfin\n", 0);
	printf("a == %d ||| b == %d\n", a, b);

	//test couleurs
	ft_printf("bonjour {blue}%d {yellow}%s lol\n", 8764, "des barres");
	ft_printf("lol %b \n", 10);
	//test erreurs
	ft_printf("%0-d", 23);
	ft_printf("%-r", 23);
	ft_printf("%+u", 12);
	ft_printf("%12.-23d", 12);
	return (0);
}
