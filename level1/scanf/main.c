#include <stdio.h>

int	ft_scanf(const char *fmt, ...);

int	main(void)
{
	char	s[128];
	int	d;
	char	c;

	while (ft_scanf("%s %d %c", s, &d, &c) == 3)
		printf("%s %d %c\n", s, d, c);
	return (0);
}
