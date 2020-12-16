#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
	char name[10];
	char num[10];

}Student;

typedef struct node {
	Student st;
	struct node* next;

}node;

typedef struct nodeList {
	int size;
	node* head;
	node* tail;

}nodeList;


void add(Student s, nodeList* a);
nodeList* createList();
char* lookup(char* ch, node* n);
char* arrysearch(char*ch,Student* students,int size);

//main함수
int main() {

    //변수선언
	char search[10];
	Student students[10] = { {"이원규","20150000"},{"김철수","20150001"},{"강민경","20150002"},{"우승엽","20150003"},{"장홍규","20150004"},{"이정호","20150005"},{"배준성","20150006"},{"최현동","20150007"},{"표승완","20150008"},{"홍성목","20150009"} };
	nodeList* studentlist = createList();
    node* nptr;

    // list에 학생추가
	for (int i = 0; i < 10; i++) {
		add(students[i], studentlist);
	}


printf("검색 : ");
scanf("%s",search);
printf("-->  ");
//linked list로 검색하기
//printf("%s",lookup(search,studentlist->head));

// arry로 검색하기
printf("%s",arrysearch(search,students,sizeof(students)/sizeof(Student)));


//동적할당 free
while (studentlist->head != NULL) {
        nptr = studentlist->head;
        studentlist->head = studentlist->head->next;
        free(nptr);

    }



free(studentlist);
}

//함수

nodeList* createList() {

	nodeList* p = (nodeList*)malloc(sizeof(nodeList));
	p->size = 0;
	p->head = NULL;
	p->tail = NULL;
	return p;

}

void add(Student s, nodeList* a) {

	int size = a->size;
	node* p;
	p = (node*)malloc(sizeof(node));
	p->st = s;
	p->next = NULL;

	if ((a->head) == NULL) {
		a->head = p;
		a->tail = p;
		(a->size)++;
	}
	else {
		a->tail->next = p;
		a->tail = p;
		(a->size)++;

	}

}

char* lookup(char* ch, node* n) {
	if (n == NULL) { return "불일치"; }
	else if (strcmp(ch, n->st.name) == 0) {
		return n->st.num;
	}
	else if (strcmp(ch, n->st.num) == 0) {
		return n->st.name;
	}
	else
		return lookup(ch, n->next);

}


char* arrysearch(char*ch,Student* students,int size){

for(int i=0;i<size;i++){
		if(strcmp(ch,students[i].name)==0){
			return students[i].num;
		}
		else if(strcmp(ch,students[i].num)==0){
			return students[i].name;
		}

}
return "불일치";

}
