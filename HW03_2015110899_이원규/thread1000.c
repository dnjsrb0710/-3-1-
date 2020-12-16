#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* sub1000();
void* add1000();
volatile int num=0;// 전역변수 num

//main함수 시작
int main(int argc,char*argv[]){

//argv 입력오류 메시지
if(argc!=2){
	printf("입력오류!!");
	exit(0);
}
pthread_t pthread[10000]; //thread id 저장
int th; // 쓰레드 생성결과 저장 변수 (성공시:0)
int result; // 쓰레드 조인결과 저장 변수 (성공시:0)


//전체 30번 반복
for(int j=0;j<30;j++){

	num=atoi(argv[1]); //입력된 변수 전역변수num에 정수로 저장

	//add쓰레드 5000개 생성
	for(int i=0;i<5000;i++){

		th=pthread_create(&pthread[i],NULL,add1000,NULL);


		if(th!=0){

			printf("스레드 생성 오류!!!");
			exit(1);
		}
	}

	//sub쓰레드 5000개 생성
	for(int i=0;i<5000;i++){

		th=pthread_create(&pthread[i+5000],NULL,sub1000,NULL);

		if(th!=0){
		
			printf("thread create error!!");
			exit(1);
		}

	}

	//모든 쓰레드 join하기 
	for(int i=0;i<10000;i++){

		result=pthread_join(pthread[i],NULL);
		
		if(result!=0){
			printf("thread join error!!");
		}
	}

//최종 결과 출력
printf("%d\n",num);


}


}


//1000번 더하는 add함수
void* add1000(){

	for(int j=0;j<1000;j++){
		num++;
	}
}
//1000번 빼는 sub함수
void* sub1000(){
	for(int j=0;j<1000;j++){
		num--;
	}
}

