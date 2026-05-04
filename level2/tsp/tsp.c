#include <stdio.h>
#include <math.h>

#define MAX 11
typedef struct{float x,y;} City;
static City c[MAX]; static float d[MAX][MAX],best; static int n,used[MAX],path[MAX];
static float dist(City a,City b){float dx=a.x-b.x,dy=a.y-b.y;return sqrtf(dx*dx+dy*dy);}
static void search(int k,float len){if(k==n){len+=d[path[n-1]][path[0]];if(len<best)best=len;return;}for(int i=0;i<n;i++)if(!used[i]){float add=k?d[path[k-1]][i]:0;used[i]=1;path[k]=i;search(k+1,len+add);used[i]=0;}}

int	main(void)
{int i,j;while(fscanf(stdin," %f , %f",&c[n].x,&c[n].y)==2)n++;if(!n)return (fprintf(stdout,"0.00\n"),0);for(i=0;i<n;i++)for(j=0;j<n;j++)d[i][j]=dist(c[i],c[j]);best=1e9;search(0,0);fprintf(stdout,"%.2f\n",best);return 0;}

/*
Line 1: Include stdio.h for fscanf and fprintf.
Line 2: Include math.h for sqrtf.
Line 4: MAX is the biggest city count allowed.
Line 5: City holds one point with x and y.
Line 10: These globals store all data for the search.
Line 17: dist computes the straight-line distance.
Line 23: search tries all possible visit orders.
Line 26: When we used all cities, close the loop.
Line 33: Otherwise, pick an unused city and recurse.
Line 38: add is the extra distance to the next city.
Line 43: main is the program entry point.
Line 47: Read all "x, y" pairs from stdin.
Line 49: If there are no cities, print 0.00.
Line 53: Precompute all pair distances.
Line 62: Start the search and print the best length.
*/
