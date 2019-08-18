#include <stdio.h>
#include <stdlib.h>


typedef struct node {
   int data;
   struct node *next;
}nodetype;
nodetype *head = NULL;
//display the list
void printList()
{
   nodetype *ptr = head;
   printf("\n[head] =>");
   while(ptr != NULL) {        
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }
   printf(" [null]\n");
}
/* Function to reverse the linked list */
void printReverse(nodetype* head) 
{ 
    // Base case   
    if (head == NULL) 
       return; 
  
    // print the list after head node 
    printReverse(head->next); 
  
    // After everything else is printed, print head 
    printf("%d <=", head->data); 
} 
//boolean return about emptiness
int empty_l()
{if(head==NULL)return 1;else return 0;}
//boolean return if the pointer is at end or not
int atend_l(nodetype *cur) 
{
	if (cur == NULL)
	return 1;
	else
	return 0;
}
//insert link at the first location
void insertFront(int data)
{
   nodetype *link = (nodetype*) malloc(sizeof(nodetype));
   link->data = data;
   link->next = head;
   head = link;
}
//Insert after a particular position
void insertAfter(int pos,int data)
{
	nodetype *link = (nodetype*) malloc(sizeof(nodetype));
	nodetype *ptr = head;
	while(pos--)
	ptr = ptr->next;
	nodetype *temp = ptr;
	temp=temp->next;
	link->data=data;
	link->next=temp;
	ptr->next=link;
}
//delete the front element
void deleteFront()
{
   nodetype *link = (nodetype*) malloc(sizeof(nodetype));
   link= head->next;
   head = link;
}
//delete an element after a particular position
void deleteAfter(int pos)
{
	nodetype *ptr = head;
	while(pos--)
	ptr = ptr->next;
	nodetype *temp = ptr;
	temp=temp->next;
	temp=temp->next;
	ptr->next=temp;
}
int main()
{
   int item;empty_l();
   insertFront(6);
   insertFront(7);
   insertFront(16);
   insertFront(20);
   insertFront(96);
   printList();
   printf("\n");
   insertAfter(3,45);
   printList();
   printf("\n");
   deleteFront();
   printList();
   printf("\n");
   deleteAfter(3);
   printList();
   printf("\n");
   printReverse(head);
   return 0;
}