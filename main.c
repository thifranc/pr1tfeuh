#include "libftprintf.h"
#include <wchar.h>
#include <locale.h>
//segfault if %s et arg = int
int		main(void)
{
	/*char* l = setlocale(LC_ALL, "");
	if (l == NULL)
		printf("locale not set\n");
	else
		printf("set %s\n", l);
		*/
	char	*ptr;
	char	lol;

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
	printf("\033[32mref==>%lsfin\n\033[0m", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ");
	printf("resultat de ma fonction : \n");
	ft_printf("\033[33mmoi==>\033[0m%Sfin\n", L"ᓀᐦᐃᔭᐍᐏᐣᐊᓂᔑᓇᐯᒧᐎᐣᑕᗸᒡᑯᖾᖹᓱᖽᐧᖿᐃᓄᒃᑎᑐᑦ");

	ft_printf("%s", 12);
	return (0);
}
