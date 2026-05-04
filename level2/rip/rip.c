#include <stdio.h>

static int	min_remove(char *s){int o=0,r=0;for(int i=0;s[i];i++)if(s[i]=='(')o++;else if(o)o--;else r++;return r+o;}
static void	solve(char *s,int i,int o,int c,int rm,int min,char *b){if(!s[i]){if(o==c&&rm==min){b[i]=0;puts(b);}return;}b[i]=s[i];if(s[i]=='(')solve(s,i+1,o+1,c,rm,min,b);else if(o>c)solve(s,i+1,o,c+1,rm,min,b);b[i]=' ';solve(s,i+1,o,c,rm+1,min,b);}

int	main(int ac,char **av)
{char *s;int min,n;if(ac!=2)return 1;s=av[1];min=min_remove(s);for(n=0;s[n];n++);{char b[n+1];solve(s,0,0,0,0,min,b);}return 0;}

/*
Line 1: Include stdio.h for puts.
Line 3: min_remove counts how many parentheses to remove.
Line 17: solve builds and prints all valid outputs.
Line 19: If we are at the end, check and print.
Line 26: Try keeping this parenthesis if it stays valid.
Line 29: Also try removing it by writing a space.
Line 33: main is the program entry point.
Line 38: If the argument count is wrong, stop.
Line 40: Get the input string.
Line 41: Find the minimum number to remove.
Line 42: Find the string length.
Line 45: Create a buffer on the stack.
Line 46: Call the solver and print results.
*/

