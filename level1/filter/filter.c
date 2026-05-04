#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int	main(int ac,char **av){
	char *pat,*buf=0,*p,*f,*nb,tmp[4096];
	size_t plen=0,len=0,cap=0,need,n,rem,i;ssize_t r;
	if(ac!=2||!av[1][0])return 1;
	pat=av[1];
	plen=strlen(pat);
	while((r=read(0,tmp,sizeof tmp))>0){
		need=len+(size_t)r;if(need>cap){n=cap?cap*2:(size_t)r;while(n<need)n*=2;
			nb=realloc(buf,n);if(!nb){perror("Error");free(buf);return 1;}buf=nb;cap=n;}
		memmove(buf+len,tmp,(size_t)r);len+=(size_t)r;}
	if(r<0){perror("Error");free(buf);return 1;}
	if(!buf)return 0;
	p=buf;rem=len;while((f=memmem(p,rem,pat,plen))){
		write(1,p,(size_t)(f-p));for(i=0;i<plen;i++)write(1,"*",1);
		rem-=(size_t)(f-p)+plen;p=f+plen;}
	write(1,p,rem);free(buf);return 0;}

/*
Line 1: This lets us use read and write.
Line 2: This lets us use strlen, memmem, and memmove.
Line 3: This lets us use malloc, realloc, and free.
Line 4: This lets us use perror.
Line 6: main is where the program starts.
Line 8: These are the main variables we will use.
Line 15: If the argument is missing or empty, stop.
Line 17: pat is the word we want to hide.
Line 18: buf starts as NULL because we have no data yet.
Line 19: plen is the length of the pattern word.
Line 20: len is how many bytes we already stored.
Line 21: cap is how big the buffer is right now.
Line 22: Read from stdin until there is nothing left.
Line 24: If new data will not fit, grow the buffer.
Line 26: Pick a new size and keep growing until it is enough.
Line 29: Try to grow the buffer with realloc.
Line 30: If that fails, print the error and stop.
Line 37: Copy the new bytes into the end of buf.
Line 38: Update len to include the new bytes.
Line 40: If read fails, print the error and stop.
Line 46: If there was no input at all, exit cleanly.
Line 48: Start scanning the big buffer for the pattern.
Line 52: memmem finds the next match inside the remaining bytes.
Line 54: Write everything before the match.
Line 55: Write one '*' for each character in the pattern.
Line 57: Move forward past the match.
Line 59: Write any remaining bytes after the last match.
Line 61: Free the big buffer.
Line 62: Exit cleanly with 0.
*/
