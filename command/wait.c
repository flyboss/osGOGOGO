#include "stdio.h"
#define HZ             100  
int main(int argc, char * argv[])
{
	char *s=argv[1];
	char *p;
	int n=0;
	for(p=s;*p!='\0';p++)
    	n=n*10+*p-'0';
    int t = getticks();
    while(((getticks() - t) * 1000 / HZ) < n) {}
    printf("%s ms has gone\n", s);
}
