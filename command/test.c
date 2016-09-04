#include "stdio.h"

int main(int argc, char * argv[])
{
	
	int fd;
	int n;
	const char filename[] = argv[1];


	/* create */
	fd = open(filename, O_CREAT | O_RDWR);
	if(fd!=-1)
		printf("File %s created success.\n", filename);
	else
		printf("File %s created fail.\n", filename);

	/* write */
	n = write(fd, bufw, strlen(bufw));
	assert(n == strlen(bufw));

	/* close */
	close(fd);

	/* open */
	fd = open(filename, O_RDWR);
	assert(fd != -1);
	printf("File opened. fd: %d\n", fd);

	/* read */
	n = read(fd, bufr, rd_bytes);
	assert(n == rd_bytes);
	bufr[n] = 0;
	printf("%d bytes read: %s\n", n, bufr);

	/* close */
	close(fd);

	return 0;
}
