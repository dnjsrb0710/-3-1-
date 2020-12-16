#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){

	if(argc!=3){
		printf("입력오류");
		exit(0);}    
	int num1,num2;

	num1=atoi(argv[1]);
	num2=atoi(argv[2]);

	printf("%d",num1-num2);


}
