#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>

int main( )
{
	struct stat st;// st.st_size   st.st_ino  st_blksize
	struct tm dt;
        int fd;
	
	stat("1.c", &st);

	printf("File size = %lu\n",st.st_size);
	printf("File inode = %lu\n", st.st_ino);
	printf("size disc of blocks = %lu\n",st.st_blksize);
    printf("No. of 512 byte blocks allocated = %ld\n",st.st_blocks);
	
	close(fd);
	return 0;
}