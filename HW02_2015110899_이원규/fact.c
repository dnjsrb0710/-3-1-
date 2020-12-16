#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){

	if(argc!=2){
		printf("입력오류");
		exit(0);}
	int num1,fact;
	fact=1;

	num1=atoi(argv[1]);
	for(int i=1;i<=num1;i++){
fact=fact*i;

	}

	if(num1<0){
		printf("입력오류");}
	else
		printf("%d",fact);


}
