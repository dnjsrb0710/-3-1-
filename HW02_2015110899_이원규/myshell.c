#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
	
printf(">>");

char program[50];
char *argv[10];
int i=0;
pid_t pid;

scanf("%[^\n]s",program);
char *ptr=strtok(program," ");

while(ptr!=NULL){
argv[i]=ptr;
ptr=strtok(NULL," ");
i++;
}


pid=fork();
if(pid==0){
execvp(argv[0],argv);
}
if(pid>0){
	wait(NULL);
	
}

}


