#include "broken_gnl.h"

static size_t	slen(char *s){size_t i=0;while(s&&s[i])i++;return i;}
static char	*schr(char *s,char c){while(s&&*s&&*s!=c)s++;return s&&*s==c?s:0;}
static char	*ret0(char *p){free(p);return 0;}
static int	app(char **d,char *s,size_t n){size_t l=slen(*d),i;char *t=malloc(l+n+1);
	if(!t)return 0;
	for(i=0;i<l;i++)t[i]=(*d)[i];
	for(i=0;i<n;i++)t[l+i]=s[i];
	t[l+n]=0;free(*d);*d=t;return 1;}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1];
	char		*r=0,*nl;int rd;size_t i,l;
	while(!(nl=schr(b,'\n'))){
		if(!app(&r,b,slen(b)))return ret0(r);
		rd=read(fd,b,BUFFER_SIZE);
		if(rd<0)return ret0(r);
		if(!rd){b[0]=0;break;}
		b[rd]=0;}
	if(nl){if(!app(&r,b,nl-b+1))return ret0(r);l=slen(nl+1);for(i=0;i<=l;i++)b[i]=nl[1+i];}
	else if(!r||!*r)return ret0(r);
	return r;
}

/*
Line 1: This lets us use the function prototype and BUFFER_SIZE.
Line 3: ft_strlen counts characters and handles NULL safely.
Line 9: ft_strchr finds the first '\n' in a string.
Line 16: append makes a bigger string and frees the old one.
Line 30: get_next_line returns one line from the file.
Line 32: b keeps leftover bytes between calls.
Line 33: r is the line being built.
Line 34: nl points to a '\n' if we find one.
Line 35: rd is the number of bytes read.
Line 36: i and l are loop helpers.
Line 38: Keep reading until we see a newline or EOF.
Line 40: Add current buffer into r.
Line 42: Read more bytes from the file.
Line 44: If read fails, free and return NULL.
Line 46: If read returns 0, we hit EOF.
Line 48: Add a '\0' so the buffer is a C string.
Line 50: If we found a newline, append through it.
Line 52: If append fails, free and return NULL.
Line 54: Move leftover bytes after the newline into b.
Line 57: If no newline and no data, return NULL.
Line 59: Return the built line to the caller.
*/