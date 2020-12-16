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

//main�Լ�
int main() {

    //��������
	char search[10];
	Student students[10] = { {"�̿���","20150000"},{"��ö��","20150001"},{"���ΰ�","20150002"},{"��¿�","20150003"},{"��ȫ��","20150004"},{"����ȣ","20150005"},{"���ؼ�","20150006"},{"������","20150007"},{"ǥ�¿�","20150008"},{"ȫ����","20150009"} };
	nodeList* studentlist = createList();
    node* nptr;

    // list�� �л��߰�
	for (int i = 0; i < 10; i++) {
		add(students[i], studentlist);
	}


printf("�˻� : ");
scanf("%s",search);
printf("-->  ");
//linked list�� �˻��ϱ�
//printf("%s",lookup(search,studentlist->head));

// arry�� �˻��ϱ�
printf("%s",arrysearch(search,students,sizeof(students)/sizeof(Student)));


//�����Ҵ� free
while (studentlist->head != NULL) {
        nptr = studentlist->head;
        studentlist->head = studentlist->head->next;
        free(nptr);

    }



free(studentlist);
}

//�Լ�

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
	if (n == NULL) { return "����ġ"; }
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
return "����ġ";

}
