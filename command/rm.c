#include "stdio.h"
#include "string.h"

int main(int argc, char * argv[])
{
	int fd;
	const char *filename=argv[1];
	fd=open(filename,O_RDWR);
	if(fd==-1)
	{
		printf("cannot find %s\n",filename );
		return 0;
	}
	const int wr_bytes=512;
	char content[wr_bytes];
	int r=read(fd,content,wr_bytes);
	if(content[0]=='E'&&content[1]=='O'&&content[2]=='F')
	{
		printf("cannot find %s\n",filename );
		close(fd);
		return 0;
	}
	int m;
	for(m=0;m<wr_bytes;m++)
		if(content[m]==0)
			break;
	for(int i=0;i<=m;i++)
		content[i]=0;	
	content[0]='E';
	content[1]='O';
	content[2]='F';
	

	close(fd);
	
	fd=open(filename,O_RDWR);
	int n=write(fd,content,512);
	if(n!=512)
		printf("remove fail\n");
	else
		printf("remove success\n");

	close(fd);
	return 0;
}
