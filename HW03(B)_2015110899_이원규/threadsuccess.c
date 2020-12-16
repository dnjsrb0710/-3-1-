#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* sub100();
void* add100();
void swap(); //전역변수 값이 꺠질 확률을 더 높일 수 있는 함수
volatile int num=0;// 전역변수 num
pthread_mutex_t mutex;//mutex 객체 

//main함수 시작
int main(int argc,char*argv[]){

//argv 입력오류 메시지
if(argc!=2){
	printf("입력오류!!");
	exit(0);
}
pthread_t pthread[10];//thread id 저장 
int th; // 쓰레드 생성결과 저장 변수 (성공시:0)
int result; // 쓰레드 조인결과 저장 변수 (성공시:0)
int mresult; // mutex생성결과 저장 변수 (성공시 :0)


//default값의 기본mutex 생성
pthread_mutex_init(&mutex,NULL);


if(mresult!=0){

	printf("mutex 생성실패!!!");
	exit(0);
}


//전체 30번 반복
for(int j=0;j<30;j++){

	num=atoi(argv[1]); //입력된 변수 전역변수num에 정수로 저장

	//add쓰레드 5개 생성
	for(int i=0;i<5;i++){

		th=pthread_create(&pthread[i],NULL,add100,NULL);


		if(th!=0){

			printf("스레드 생성 오류!!!");
			exit(1);
		}
	}

	//sub쓰레드 5개 생성
	for(int i=0;i<5;i++){

		th=pthread_create(&pthread[i+5],NULL,sub100,NULL);

		if(th!=0){
		
			printf("thread create error!!");
			exit(1);
		}

	}

	//모든 쓰레드 join하기 
	for(int i=0;i<10;i++){

		result=pthread_join(pthread[i],NULL);
		
		if(result!=0){
			printf("thread join error!!");
		}
	}

//최종 결과 출력
printf("%d\n",num);


}


}


//100번 더하는 add함수
void* add100(){

	for(int j=0;j<100;j++){
		pthread_mutex_lock(&mutex); // 다른 thread가 접근하지 못하도록 설정
		swap();
		num++;
		pthread_mutex_unlock(&mutex); // 다른 thread가 접근가능하도록 설정
	}
}
//100번 빼는 sub함수
void* sub100(){
	for(int j=0;j<100;j++){
		
		pthread_mutex_lock(&mutex);
		swap();
		num--;
		pthread_mutex_unlock(&mutex);
	}
}

//전역변수 값이 꺠질 확률을 더 높일 수 있는 함수
void swap(){
	volatile int tmp;

	for(int k=0;k<10000;k++){
			tmp=num;
			num=tmp;
			}

}



