#include <stdlib.h>
#include <stdio.h>

static int	abs_i(int x){return x<0?-x:x;}
static int	safe(int *b,int c,int r){int i=0;while(i<c){if(b[i]==r||abs_i(b[i]-r)==c-i)return 0;i++;}return 1;}
static void	print(int *b,int n){for(int i=0;i<n;i++)fprintf(stdout,"%d%s",b[i],i==n-1?"\n":" ");}
static void	solve(int *b,int c,int n){if(c==n){print(b,n);return;}for(int r=0;r<n;r++)if(safe(b,c,r)){b[c]=r;solve(b,c+1,n);}}

int	main(int ac,char **av)
{
	int n,*b;
	if(ac!=2)return 1;
	n=atoi(av[1]); if(n<=0)return 1;
	b=malloc((size_t)n*sizeof(int)); if(!b)return 1;
	solve(b,0,n); free(b); return 0;
}

/*
Line 1: Include stdlib.h for atoi and malloc.
Line 2: Include stdio.h for fprintf and stdout.
Line 4: abs_i makes negative numbers positive.
Line 8: safe checks if a queen can go here safely.
Line 18: print shows one solution with spaces.
Line 27: solve tries all rows in the current column.
Line 40: main is the program entry point.
Line 44: If we did not get one argument, stop.
Line 46: Read n from the argument.
Line 47: If n is not positive, stop.
Line 49: Allocate memory for the board.
Line 51: If malloc fails, stop.
Line 53: Run the backtracking solver.
Line 54: Free the board and exit cleanly.
*/