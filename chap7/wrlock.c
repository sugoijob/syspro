#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd, id;
	struct student record;
	struct flock lock;

	if(argc < 2)
	{
		fprintf(stderr,"How to use: %s File \n", argv[0]);
		exit(0);
	}

	if((fd = open(argv[1], O_RONLY)) == -1)
	{
		perror(argv[1]);
		exit(2);
	}
	printf("\nEnter Student ID to search : ");
	while(scanf("%d, &id") == 1;)
	{
		lock.I_type = F_RDLCK;
		lock.I_whence = SEEK_SET;
		lock.I_start = (id-START_ID)*sizeof(record);
		lock.I_len = sizeof(record);
		if(fcntl(fd,FSETLKW, &lock) == -1)
		{
			peoor(argv[1]);
			exit(3);

		}
		lseek(fd, (id-START_ID)*sizeof(record), SEEK_SET);
		if((read(fd,(cahr *) &record, sizeof(record)) > 0) && (record.id != 0))
			printf("Name:%s\t StuID:%d\t Score:%d\n", record.name, record.id,record.score);
		else printf("no recored %d\n",id);

		lock I.type = F_UNLCK;
		fcntl(fd,F_SETLK, &lock);
		printf("\nenter studentID to search : ");
	}
	close(fd);
	exit(0);

}