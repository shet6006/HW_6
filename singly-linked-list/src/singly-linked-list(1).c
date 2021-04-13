/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* �ʿ��� ������� �߰� */

typedef struct Node {
   int key;
   struct Node* link;
} listNode;

typedef struct Head {
   struct Node* first;
}headNode;


/* �Լ� ����Ʈ */
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
   setvbuf(stdout, NULL, _IONBF, 0); // Windows �� Eclipse�� Consoleâ ���� �� ������ ���� ����
   setvbuf(stderr, NULL, _IONBF, 0);
   char command;
   int key;
   headNode* headnode=NULL;

   do{
      printf("---------------------[�赿��] [2020039023]------------------------\n");
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

   /* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
   if(h != NULL)
      freeList(h);

   /* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
   headNode* temp = (headNode*)malloc(sizeof(headNode));
   temp->first = NULL;
   return temp;
}

int freeList(headNode* h){
   /* h�� ����� listNode �޸� ����
    * headNode�� �����Ǿ�� ��.
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
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {

   listNode* node = (listNode*)malloc(sizeof(listNode));
   node->key = key;

   node->link = h->first;
   h->first = node;

   return 0;
}


/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode));
   node->key=key; //���Ḯ��Ʈ ���ο� ��忡 Ű�� ���� ���������
   node->link=NULL; //��� ���� ��ũ�� ��� ���� ���� �����Ҽ��� �ֵ��� ��
   if(h->first==NULL){ //����尡 ���������, ���Ḯ��Ʈ�� ��������Ƿ� �Է¹��� Ű�� ���� ù��° ��尡 �ǵ��� ��
      h->first=node;
      return 0;
   }
   listNode* front = h->first;
   listNode* rear = h->first;
   while(front!=NULL){
      if(front->key>=key){
    	  node->link=front;
    	  rear->link=node;
         }
      }
   return 0;
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode));
   node->key=key;
   node->link=NULL;
   if(h->first==NULL){
      h->first=node;
      return 0;
   }
   listNode* rear=h->first;
   if(rear==NULL)
	   rear=node; //������ ��尡 ���� ��� ���ο� ��带 ù ���� ����
   else{
	   while(rear->link!=NULL){ //��带 ���Ḯ��Ʈ�� ���� ������ ��忡 �����ϴ� ����
		   rear=rear->link;
		   rear->link=node;
	   }
   }
   return 0;
}


/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {

}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {

   return 0;

}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {

   return 0;
}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
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
