#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "data.h"

int main(int argc, char *argv[])
{
	char savedtext[10][100];
	char buf;
	int fd, a;

	struct data record;
	read(fd, &buf,1);
	savedtext[0][0] = buf;
	read(fd, &buf, 1);
	savedtext[0][1] = buf;
	
	lseek(fd,(record.line[MAX])*sizeof(record), SEEK_SET);
			if((read(fd, (char *) &record, sizeof(record)) != 0))
				printf("%s\n", record.line);
				printf("%s\n", savedtext[1]);
	//printf("%s\n", savedtext[1]);
	//printf("%s\n", savedtext[2]);
	close(fd);
	exit(0);
}
