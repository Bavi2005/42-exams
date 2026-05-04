#include <stdio.h>
#include <stdlib.h>

static void	print(int *a,int *p,int n){int f=1;for(int i=0;i<n;i++)if(p[i]){if(!f)printf(" ");printf("%d",a[i]);f=0;}printf("\n");}
static void	dfs(int *a,int *p,int n,int i,int sum,int tgt){if(i==n){if(sum==tgt)print(a,p,n);return;}p[i]=1;dfs(a,p,n,i+1,sum+a[i],tgt);p[i]=0;dfs(a,p,n,i+1,sum,tgt);}

int	main(int ac,char **av)
{int tgt,n,*a,*p,i;if(ac<2)return 1;tgt=atoi(av[1]);n=ac-2;a=malloc((size_t)n*sizeof(int));p=calloc((size_t)n,sizeof(int));if(!a||!p)return 1;for(i=0;i<n;i++)a[i]=atoi(av[i+2]);dfs(a,p,n,0,0,tgt);free(a);free(p);return 0;}

/*
Line 1: Include stdio.h for printf.
Line 2: Include stdlib.h for atoi, malloc, and calloc.
Line 4: print writes one subset in order.
Line 20: dfs tries include or skip for each item.
Line 33: main is the program entry point.
Line 39: If there is no target, stop.
Line 41: Read the target sum.
Line 42: Count how many numbers are in the set.
Line 43: Allocate the numbers array.
Line 44: Allocate the include flags array.
Line 45: If allocation fails, stop.
Line 47: Read each number from the arguments.
Line 49: Run the DFS to print all matches.
Line 50: Free memory and exit cleanly.
*/