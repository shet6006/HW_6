/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node {
   int key;
   struct Node* link;
} listNode;

typedef struct Head {
   struct Node* first;
}headNode;


/* 함수 리스트 */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
   setvbuf(stdout, NULL, _IONBF, 0); // Windows 용 Eclipse의 Console창 글자 안 나오는 오류 수정
   setvbuf(stderr, NULL, _IONBF, 0);
   char command;
   int key;
   headNode* headnode=NULL;

   do{
      printf("---------------------[김동원] [2020039023]------------------------\n");
      printf("                     Singly Linked List                         \n");
      printf("----------------------------------------------------------------\n");
      printf(" Initialize    = z           Print         = p \n");
      printf(" Insert Node   = i           Delete Node   = d \n");
      printf(" Insert Last   = n           Delete Last   = e\n");
      printf(" Insert First  = f           Delete First  = t\n");
      printf(" Invert List   = r           Quit          = q\n");
      printf("----------------------------------------------------------------\n");

      printf("Command = ");
      scanf(" %c", &command);

      switch(command) {
      case 'z': case 'Z':
         headnode = initialize(headnode);
         break;
      case 'p': case 'P':
         printList(headnode);
         break;
      case 'i': case 'I':
         printf("Your Key = ");
         scanf("%d", &key);
         insertNode(headnode, key);
         break;
      case 'd': case 'D':
         printf("Your Key = ");
         scanf("%d", &key);
         deleteNode(headnode, key);
         break;
      case 'n': case 'N':
         printf("Your Key = ");
         scanf("%d", &key);
         insertLast(headnode, key);
         break;
      case 'e': case 'E':
         deleteLast(headnode);
         break;
      case 'f': case 'F':
         printf("Your Key = ");
         scanf("%d", &key);
         insertFirst(headnode, key);
         break;
      case 't': case 'T':
         deleteFirst(headnode);
         break;
      case 'r': case 'R':
         invertList(headnode);
         break;
      case 'q': case 'Q':
         freeList(headnode);
         break;
      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");
         break;
      }

   }while(command != 'q' && command != 'Q');

   return 1;
}

headNode* initialize(headNode* h) {

   /* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
   if(h != NULL)
      freeList(h);

   /* headNode에 대한 메모리를 할당하여 리턴 */
   headNode* temp = (headNode*)malloc(sizeof(headNode));
   temp->first = NULL;
   return temp;
}

int freeList(headNode* h){
   /* h와 연결된 listNode 메모리 해제
    * headNode도 해제되어야 함.
    */
   listNode* p = h->first;

   listNode* prev = NULL;
   while(p != NULL) {
      prev = p;
      p = p->link;
      free(prev);
   }
   free(h);
   return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

   listNode* node = (listNode*)malloc(sizeof(listNode));
   node->key = key;

   node->link = h->first;
   h->first = node;

   return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode));
   node->key=key; //연결리스트 새로운 노드에 키의 값을 저장시켜줌
   node->link=NULL; //노드 뒤의 링크를 비워 다음 노드와 연결할수록 있도록 함
   if(h->first==NULL){ //헤드노드가 비어있으면, 연결리스트가 비어있으므로 입력받은 키의 값이 첫번째 노드가 되도록 함
      h->first=node;
      return 0;
   }
   listNode* front = h->first;
   listNode* rear = h->first;
   if(front->key<key){
	   node->link=front->link;
	   front->link=node;
   }
   rear->link=node;
   return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode));
   node->key=key; //노드에 키 할당
   node->link=NULL; //링크를 비워줌
   if(h->first==NULL){ //첫번째 노드가 비어있으면 첫번째 노드에 새로운 노드를 할당
      h->first=node;
      return 0;
   }
   listNode* rear=h->first;
   if(rear==NULL)
	   rear=node; //마지막 노드가 없을 경우 새로운 노드를 첫 노드로 지정
   else{
	   while(rear->link!=NULL){ //리스트의 마지막 노드를 찾는다
		   rear=rear->link; //노드를 한칸씩 뒤로 옮긴다
	   }
	   rear->link=node; //찾은 마지막노드에 새로운 노드를 삽입한다
   }
   return 0;
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {
	listNode *front=h->first; //맨 앞 노드를 가리키는 front
	if (front == NULL)
	{
		printf("리스트가 비어있습니다!\n");
		return 0;
	}
	else{
		h->first = front->link; //맨 앞 노드를 다음 노드로 바꾸어준다
		free(front); //맨 앞이었던 노트의 메모리를 해제
	}

	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {
	listNode*node=h->first;
	listNode*rear=NULL;
	while(node!=NULL){ //노드를 끝까지 돈다
		if(node->key==key){ //key가 같은 노드를 찾으면
			rear->link=node->link; //다음 노드에 삭제할 노드가 가지고 있던 링크를 할당해준다
		}
		free(node);
	}

   return 0;

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
	listNode* node; //삭제하기 전의 노드
	listNode* rear; //삭제할 마지막 노드
	if(h->first==NULL){ //리스트가 비어있을때
		printf("리스트가 비어있습니다!\n");
	}
	else{
		node=h->first;
		rear=h->first;
		while(rear->link!=NULL){ //링크가 비어있다면 마지막 노드이므로 찾을때까지 반복
			node=rear; //노드와 rear를 하나씩 뒤로 이동시켜준
			rear=rear->link;
		}
	}
	free(rear);
	node->link=NULL;
   return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {

   return 0;
}

void printList(headNode* h) {
   int i = 0;
   listNode* p;

   printf("\n---PRINT\n");

   if(h == NULL) {
      printf("Nothing to print....\n");
      return;
   }

   p = h->first;

   while(p != NULL) {
      printf("[ [%d]=%d ] ", i, p->key);
      p = p->link;
      i++;
   }

   printf("  items = %d\n", i);
}
