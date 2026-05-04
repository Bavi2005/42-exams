#include <unistd.h>

static int	len(char *s){int i=0;while(s[i])i++;return i;}
static void	swap(char *a,char *b){char t=*a;*a=*b;*b=t;}
static void	sort(char *s,int n){for(int i=0;i<n-1;i++)for(int j=0;j<n-1-i;j++)if(s[j]>s[j+1])swap(s+j,s+j+1);}
static int	next(char *s,int n){int i=n-2,j,a,b;while(i>=0&&s[i]>=s[i+1])i--;if(i<0)return 0;j=n-1;while(s[j]<=s[i])j--;swap(s+i,s+j);a=i+1;b=n-1;while(a<b){swap(s+a,s+b);a++;b--;}return 1;}
static void	put(char *s){for(int i=0;s[i];i++)write(1,s+i,1);write(1,"\n",1);}

int	main(int ac,char **av)
{char *s;int n;if(ac!=2)return 1;s=av[1];n=len(s);sort(s,n);put(s);while(next(s,n))put(s);return 0;}

/*
Line 1: Include unistd.h for write.
Line 3: len counts how long the string is.
Line 9: swap swaps two characters.
Line 15: sort puts the string in alphabetical order.
Line 28: next makes the next permutation in order.
Line 35: It swaps and reverses the tail part.
Line 46: put prints the string and a newline.
Line 54: main is the program entry point.
Line 58: If there is not exactly one argument, stop.
Line 60: Get the input string and its length.
Line 62: Print the first (sorted) permutation.
Line 63: Keep printing until there are no more.
*/