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

	//read old file
	const int rd_bytes=512;
	char bufr[rd_bytes];
	int n=read(fd,bufr,rd_bytes);
	
	if(bufr[0]=='E'&&bufr[1]=='O'&&bufr[2]=='F')
	{
		printf("cannot find %s\n",filename );
		close(fd);
		return 0;
	}


	int m;
	for(m=0;m<rd_bytes;m++)
		if(bufr[m]==0)
			break;
	close(fd);



	fd=open(filename,O_RDWR);
	const int wr_bytes=512;
	char content[wr_bytes];
	int r=read(0,content,wr_bytes);
	content[r]=0;
	if(r+m>512)
	{
		printf("beyond file size\n");
		close(fd);
		return 0;
	}
	char *p=argv[2];
	if(*p=='r')
	{
		lseek(fd,0,1);
		n=write(fd,content,strlen(content));
		if(n!=strlen(content))
			printf("rewrite fail\n");
		else
			printf("rewrite success\n");

		close(fd);
		return 0;
	}
	else
	{
		//copy
		int i,j;
		for(i=m,j=0;i<512&&j<r;i++,j++)
		{
			bufr[i]=content[j];
		}
		bufr[i]=0;

	
		n=write(fd,bufr,strlen(bufr));
		if(n!=strlen(bufr))
			printf("write fail\n");
		else
			printf("write success\n");

		close(fd);
		return 0;
	}	
}
