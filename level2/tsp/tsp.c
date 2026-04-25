#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 11

typedef struct { float x, y; } City;

City	cities[MAX];
int	n;
float	dist[MAX][MAX];
int	used[MAX];
int	path[MAX];
float	best = 1e9;

float distance(City a, City b)
{
	return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void search(int k, float length)
{
	int i = 0;
	if (k == n)
	{
		length += dist[path[n - 1]][path[0]];
		if (length < best)
			best = length;
		return ;
	}
	while (i < n)
	{
		if (!used[i])
		{
			used[i] = 1;
			path[k] = i;
			search(k + 1, length + (k > 0 ? dist[path[k - 1]][i] : 0));
			used[i] = 0;
		}
		i++;
	}
}

int main(void)
{
	int i, j;

	n = 0;
	while (fscanf(stdin, " %f , %f", &cities[n].x, &cities[n].y) == 2)
		n++;
	if (n == 0)
		return (fprintf(stdout, "0.00\n"), 0);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			dist[i][j] = distance(cities[i], cities[j]);
	best = 1e9;
	search(0, 0.0);
	fprintf(stdout, "%.2f\n", best);
	return 0;
}
