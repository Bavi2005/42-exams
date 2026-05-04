#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int	match_space(FILE *f){int c;while((c=fgetc(f))!=EOF&&isspace(c));if(c!=EOF)ungetc(c,f);return 0;}
int	match_char(FILE *f,char c){int x=fgetc(f);if(x==c)return 1;if(x!=EOF)ungetc(x,f);return 0;}
int	scan_char(FILE *f,va_list ap){int c=fgetc(f);if(c==EOF)return 0;*va_arg(ap,char*)=(char)c;return 1;}
int	scan_string(FILE *f,va_list ap){char *s=va_arg(ap,char*);int c=fgetc(f),i=0;if(c==EOF)return 0;while(c!=EOF&&!isspace(c)){s[i++]=(char)c;c=fgetc(f);}if(c!=EOF)ungetc(c,f);s[i]=0;return 1;}
int	scan_int(FILE *f,va_list ap){int c=fgetc(f),s=1,v=0;if(c=='-'||c=='+'){if(c=='-')s=-1;c=fgetc(f);}if(!isdigit(c)){if(c!=EOF)ungetc(c,f);return 0;}while(isdigit(c)){v=v*10+(c-'0');c=fgetc(f);}if(c!=EOF)ungetc(c,f);*va_arg(ap,int*)=v*s;return 1;}
int	match_conv(FILE *f,const char **fmt,va_list ap){if(**fmt=='c')return scan_char(f,ap);if(**fmt=='d'){match_space(f);return scan_int(f,ap);}if(**fmt=='s'){match_space(f);return scan_string(f,ap);}return -1;}

int	ft_vfscanf(FILE *f,const char *fmt,va_list ap){
	int n=0,c=fgetc(f);
	if(c==EOF)return EOF;
	ungetc(c,f);
	while(*fmt){
		if(*fmt=='%'){
			fmt++;if(match_conv(f,&fmt,ap)!=1)break;n++;}
		else if(isspace(*fmt))match_space(f);
		else if(match_char(f,*fmt)!=1)break;
		fmt++;}
	if(ferror(f))return EOF;
	return n;}

int	ft_scanf(const char *fmt,...)
{va_list ap;int r;va_start(ap,fmt);r=ft_vfscanf(stdin,fmt,ap);va_end(ap);return r;}

/*
Line 1: This enables variadic arguments like real scanf.
Line 2: This provides FILE, fgetc, ungetc, and ferror.
Line 3: This provides isspace and isdigit.
Line 5: match_space skips input spaces.
Line 13: match_char checks one literal character.
Line 21: scan_char reads one character into a char*.
Line 28: scan_int reads a signed integer into an int*.
Line 50: scan_string reads a word into a char* and ends it with '\0'.
Line 64: match_conv picks which scanner to use.
Line 80: ft_vfscanf parses the format string.
Line 88: If the file is empty, return EOF.
Line 90: Loop through the format characters.
Line 96: For %d, %s, %c we do a conversion.
Line 103: For spaces, we skip spaces in input.
Line 106: For other chars, the input must match.
Line 110: If a file error happened, return EOF.
Line 113: Otherwise return how many conversions worked.
Line 116: ft_scanf starts the varargs list.
Line 118: It calls the core scanner on stdin.
Line 120: It closes the varargs list and returns the count.
*/
