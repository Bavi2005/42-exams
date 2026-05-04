#include "broken_gnl.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*s;

	while ((s = get_next_line(0)))
	{
		printf("%s", s);
		free(s);
	}
	return (0);
}
