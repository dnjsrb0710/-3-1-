#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){

if(argc!=3){
printf("입력오류");
exit(0);
}

	int num1,num2;
	int a,b;
	num1=atoi(argv[1]);
	num2=atoi(argv[2]);
	a=num1/num2;
	b=num1%num2;

	if(num2==0){
		printf("입력오류");
	}
	else
		printf("몫: %d , 나머지 : %d",a,b);

	
		


}
