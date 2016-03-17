#include <unistd.h>

void	avance(char **s)
{
	(*s)++;
}

int		main(void)
{
	char	*str;

	str = "Bonjour";
	avance(&str);
	write(1, str, 4);
	return (0);
}
