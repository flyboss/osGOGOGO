#include "stdio.h"

int main(int argc, char * argv[])
{
	int fd;
	const char * filename=argv[1];
	fd = open(filename, O_RDWR);
	if(fd==-1)
	{
		printf("cannot find %s\n",filename);
		return 0;
	}	
	const int rd_bytes=512;
	char bufr[rd_bytes];
	int n=read(fd,bufr,rd_bytes);
	if(bufr[0]=='E'&&bufr[1]=='O'&&bufr[2]=='F')
	{
		printf("cannot find %s\n",filename );
		close(fd);
		return 0;
	}
	printf("%s\n",bufr );
	close(fd);
	return 0;
}
