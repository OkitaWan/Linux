#include "my.h"

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{
	int fd;
	if((fd = creat("file.hole", 0644))< 0)
		perror("creat error\n");

	if (write(fd, buf1, 10) != 10)
		perror("buf1 write error\n");

	if (lseek(fd, 40, SEEK_SET) == -1)
		perror("lseek error\n");

	if (write(fd, buf2, 10) != 10)
		perror("buf2 write erroe");

}
