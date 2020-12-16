#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char** argv){
	char buf[BUFSIZ];
	char i = 0;
	int fd = -1;
	char ch[10];

	printf("A or B :  ");
	scanf("%c", &i);
	
	if(i=='A'){
		
		printf("gpio set: %c\n", i);
		fd = open("/dev/ledtest", O_RDWR);
		printf("fd: %d\n", fd);

		for (int j = 0; j < 3; j++) {
			ch[0] = '1';
			write(fd, ch, strlen(ch), NULL);
			usleep(1000000);
			ch[0] = '0';
			write(fd, ch, strlen(ch), NULL);
			usleep(500000);
		}
		memset(buf, 0, BUFSIZ);
		read(fd, buf, strlen(ch), NULL);
		printf("read: %s \n", buf);

		close(fd);
	}
	else if (i == 'B') {
		printf("1 or 0 :  ");
		scanf("%s", ch);
		printf("gpio set: B %c\n", ch);
		fd = open("/dev/ledtest", O_RDWR);
		printf("fd: %d\n", fd);
		write(fd, ch, strlen(ch), NULL);
		memset(buf, 0, BUFSIZ);
		read(fd, buf, strlen(ch), NULL);
		printf("read: %s \n", buf);

		close(fd);

	}
	else {
		printf("error!!!! insert A or B!!!");
		exit(1);
	}
}