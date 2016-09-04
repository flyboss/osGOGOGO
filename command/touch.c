#include "stdio.h"

int main(int argc, char * argv[])
{
	int fd;
	char *filename=argv[1];
	int n;
	int flag=0;
	const int rd_bytes=512;
	char bufr[rd_bytes];
	/* create */
	fd = open(filename, O_CREAT);
	if(fd!=-1)
	{
		printf("File %s created success.\n",filename);
		close(fd);
		return 0;
	}	
	else
	{
		fd = open(filename, O_RDWR);
		if(fd!=-1)
		{
			n=read(fd,bufr,rd_bytes);
			if(bufr[0]=='E'&&bufr[1]=='O'&&bufr[2]=='F')
			{
				flag=1;
			}
			else
				printf("File %s created fail.\n", filename);
			close(fd);
		}	
		else
			printf("File %s created fail.\n", filename);
		
	}
	if(flag!=0)
	{
		fd = open(filename, O_RDWR);
		char clear[3];
		clear[0]=0;
		clear[1]=0;
		clear[2]=0;
		n=write(fd,clear,3);				
		if(n==3)
			printf("File %s created success.\n",filename);
		else
			printf("File %s created fail.\n",filename);
		close(fd);
	}
	return 0;
}
