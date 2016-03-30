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

	t = -42;

	lol = 'h';
	ptr = &lol;
	//test batard
	ft_printf("\ntest option debut :\n\n");
	printf("\033[32mref==>%+07d\n\033[0m", 33);
	printf("\033[32mref==>%+07.d\n\033[0m", 33);
	printf("resultat de ma fonction : \n");
	ft_printf("\033[33mmoi==>\033[0m%+07d\n", 33);
	ft_printf("\033[33mmoi==>\033[0m%+07.d\n", 33);

	//test option '-'
	printf("\nnouveau test option\n\n");
	printf("\033[32mref==>%-dfin\n\033[0m", 33);
	printf("\033[32mref==>% 9dfin\n\033[0m", 33);
	printf("resultat de ma fonction : \n");
	ft_printf("\033[33mmoi==>\033[0m%-dfin\n", 33);
	ft_printf("\033[33mmoi==>\033[0m% 9dfin\n", 33);

	//test option '#'
	printf("\n nouveau test\n\n");
	printf("\033[32mref==>%011xfin\n\033[0m", 33);
	printf("resultat de ma fonction : \n");
	ft_printf("\033[33mmoi==>\033[0m%011xfin\n", 33);

	//test option modif longueur
	printf("\n nouveau test\n\n");
	printf("\033[32mref==>%15ldfin\n\033[0m", 2147364765555);
	printf("resultat de ma fonction : \n");
	ft_printf("\033[33mmoi==>\033[0m%15ldfin\n", 2147364765555);

	// test option 'p'
	printf("\n nouveau test\n\n");
	printf("\033[32mref==>%-23pfin\n\033[0m", ptr);
	printf("resultat de ma fonction : \n");
	ft_printf("\033[33mmoi==>\033[0m%-23pfin\n", ptr);

	//test option max string
	printf("\n nouveau test\n\n");
	printf("\033[32mref==>%.22lsfin\n\033[0m", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ");
	printf("resultat de ma fonction : \n");
	ft_printf("\033[33mmoi==>\033[0m%.22Sfin\n", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ");

	//retour ft
	printf("\n nouveau test\n\n");
	printf("\033[32m  ret ft ==>%d\n\033[m", printf("%.23lsfin", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ"));
	printf("resultat de ma fonction : \n");
	ft_printf("\033[33m  ret ft ==>%d\n\033[m", ft_printf("%.23Sfin", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ"));
	
	//test conv unsigned
	printf("\n nouveau test\n\n");
	printf("\033[32mref==>%ufin\n\033[0m", (unsigned)-42);
	printf("resultat de ma fonction : \n");
	ft_printf("\033[33mmoi==>\033[0m%ufin\n", -42);
	ft_printf("\033[33mmoi==>\033[0m%ufin\n", t);

	//test %
	ft_printf("%-5%");

	//test erreurs
	ft_printf("%0-d", 23);
	ft_printf("%-r", 23);
	ft_printf("%+u", 12);
	ft_printf("%12.-23d", 12);


	return (0);
}
