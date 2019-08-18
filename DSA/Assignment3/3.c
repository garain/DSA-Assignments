#include<stdio.h>
#include<stdlib.h>
#include "header.c"

void insertEnd(node** head,int data);
int search(node* head,int key);
int isEqual(node* head1,node* head2);
void printIn(node* head);
void printRev(node *head);
void append(node** head1,node** head2);
int size(node* head);
void del(node** head, int n);
int inOrder(node* head);//
void merge(node** head1,node** head2);//
void removeDuplicates(node** head);
void swap(node** head,int n,int m);
void lastTofirst(node** head);
void delAlt(node** head);
void rotate(node** head, int k);
void delList(node** head);
void reverse(node** head);


int main(){
    printf("This is a linkedlist programs\nEnter the following number for corresponding operations\n\n");
    printf("1,i,data to enter data in the end ith linkedlist\n");
    printf("2,i,key to search key in ith linkedlist\n");
    printf("3,i,j to check if ith and jth linkedlists are equal\n");
    printf("4,i,1 to print ith linkedlist in order\n");
    printf("4,i,2 to print ith linkedlist in reverse order\n");
    printf("5,i,j to append jth list after ith linkedlist\n");
    printf("6,n,i to delete nth node in ith linkedlist\n");
    printf("7,i to check if ith linkedlist is in order\n");
    printf("8,i,j to merge ith and jth sorted linkedlist\n");
    printf("9,i,data to enter data in begining of ith linkedlist\n");
    printf("10,i to remove duplicates in ith linkedlist\n");
    printf("11,m,n,i to swap m and nth element in ith linkedlist\n");
    printf("12,i to move last element to the first in ith linkedlist\n");
    printf("13,i to delete alternate nodes in ith linkedlist\n");
    printf("14,i,k to rotate ith linkedlist k-times counterclockwise\n");
    printf("15,i to delete ith linkedlist\n");
    printf("16,i to reverse ith linkedlist\n\n");
    printf("x to exit the program\n\n");
    node* l[100];
    int i,j,m,n,key,type,data;
    for(i=0;i<100;i++){
        init(&l[i]);
    }
    while(scanf("%d",&type)){
        switch(type){
            case 1:
            scanf(",%d,%d",&i,&data);
            insertEnd(&l[i],data);
            break;

            case 2:
            scanf(",%d,%d",&i,&key);
            search(l[i],data);
            break;

            case 3:
            scanf(",%d,%d",&i,&j);
            printf("%d\n",isEqual(l[i],l[j]));
            break;

            case 4:
            scanf(",%d,%d",&i,&n);
            if(n==1)printIn(l[i]);
            if(n==2)printRev(l[i]);
            break;

            case 5:
            scanf(",%d,%d",&i,&j);
            append(&l[i],&l[j]);
            break;

            case 6:
            scanf(",%d,%d",&n,&i);
            del(&l[i],n);
            break;
            
            case 7:
            scanf(",%d",&i);
            printf("%d\n",inOrder(l[i]));
            break;
            
            case 8:
            scanf(",%d,%d",&i,&j);
            merge(&l[i],&l[j]);
            break;
            
            case 9:
            scanf(",%d,%d",&i,&data);
            node* temp = getNode(data);
            insertFront(&l[i],&temp);
            break;
            
            case 10:
            scanf(",%d",&i);
            removeDuplicates(&l[i]);
            break;

            case 11:
            scanf(",%d,%d,%d",&m,&n,&i);
            swap(&l[i],m,n);
            break;

            case 12:
            scanf(",%d",&i);
            lastTofirst(&l[i]);
            break;

            case 13:
            scanf(",%d",&i);
            delAlt(&l[i]);
            break;

            case 14:
            scanf(",%d,%d",&i,&n);
            rotate(&l[i],n);
            break;

            case 15:
            scanf(",%d",&i);
            delList(&l[i]);
            break;

            case 16:
            scanf(",%d",&i);
            reverse(&l[i]);
            break;

            default:
            break;
        }
    }
    return 0;
}

void insertEnd(node** head,int data){
    node* target = getNode(data);
    if(isEmpty(*head))insertFront(head,&target);
    node* cur = *head;
    while(!atEnd(cur->next))cur = advance(cur);
    cur->next = target;
    target->next = NULL;
}

int search(node* head,int key){
    if(head == NULL){
        printf("The list is empty\n");
        return -1;
    }
    node* cur = head;
    while(!atEnd(cur)){
        if(cur->data == key){
            printf("Found\n");
            return 1;
        }
        cur = advance(cur);
    }
    printf("Not found\n");
    return 0;
}

int isEqual(node* head1,node* head2){
    if(head1 == NULL && head2 == NULL)return 1;
    if(head1 == NULL || head2 == NULL)return 0;
    node* cur1 = head1;node* cur2 = head2;
    while(1){
        if(cur1 == NULL && cur2 == NULL)return 1;
        if(cur1 == NULL || cur2 == NULL)return 0;
        if(cur1->data != cur2->data)return 0;
        cur1 = advance(cur1);cur2 = advance(cur2);
    }
    return 0;
}

void printIn(node* head){
    while(!atEnd(head)){
        printf("%d ",head->data);
        head = advance(head);
    }
    printf("\n");
}

void printRev(node *head){
    if(atEnd(head->next)){
        printf("%d ",head->data);
        return;
    }
    printRev(head->next);
    printf("%d ",head->data);
}

void append(node** head1,node** head2){
    node* cur = *head1;
    while(!atEnd(cur->next))cur = advance(cur);
    cur->next = *head2;
}
int size(node* head){
    node* cur = head;int size = 0;
    while(!atEnd(cur)){
        cur = advance(cur);
        size++;
    }
    return size;
}
void del(node** head, int n){
    if(n >= size(*head)){
        printf("The element you want to delete doesn't exists\n");
        return;
    }
    if(n == 0)delFront(head);
    int i;node* cur = *head;
    for(i=0;i<n-1;i++)cur = advance(cur);
    node* temp = cur->next;
    cur->next = temp->next;
    free(temp);
}
int inOrder(node* head){
	if(isEmpty(head))return 0;
	if(head->next == NULL)return 3;
  	int curFlag,prevFlag;
  	if(head->data < head->next->data)prevFlag = 1;
  	else if(head->data > head->next->data)prevFlag=2;
  	else prevFlag=3;
  	node* cur = head;
  	while(!atEnd(cur->next->next)){
    	if(cur->data < cur->next->data)curFlag = 1;
    	else if(cur->data > cur->next->data)curFlag=2;
    	else curFlag=3;
    if(prevFlag!=3 && curFlag!=3 && curFlag!=prevFlag)return 4;
    if(prevFlag==3 && curFlag!=3)prevFlag = curFlag;
    cur = cur->next;
  }
  return prevFlag;
}

void merge(node** head1,node** head2){
    if(inOrder(*head1) != inOrder(*head2)){
    	printf("Cannot be merged");
    	return;
    }
    node *i = *head1, *j = *head2,*prev = *head1;
    while(i!=NULL && j!=NULL){
    	if(i->data < j->data){
    		prev = i;
    		i = i->next;
    	}
    	else{
    		node* temp = j;
    		j = j->next;
    		temp->next = prev->next;
    		prev->next = temp; 
    		prev = prev->next;
    	}
    }
    if(j!=NULL)append(head1,&j);
}

void removeDuplicates(node** head){
    if(isEmpty(*head)){
        printf("List is empty\n");
        return;
    }
    node* cur = *head;
    while(!atEnd(cur->next)){
        if(cur->data == (cur->next)->data){
            delAfter(head,&cur);
        }
        else cur = advance(cur);
    }
}

void swap(node** head,int n,int m){
    if(m >= size(*head) || n >= size(*head)){
        printf("The element you want to swap doesn't exists\n");
        return;
    }
    node *x,*y;int i,j;
    x = *head;y = *head;
    for(i=0;i<m-1;i++)x = advance(x);
    for(i=0;i<n-1;i++)y = advance(y);
    node* tempx = x->next;
    node* tempy = y->next;
    x->next = y->next;
    y->next = tempx;
    node* temp = tempx->next;
    tempx->next = tempy->next;
    tempy->next = temp;
}

void lastTofirst(node** head){
    if(isEmpty(*head)){
        printf("List is empty\n");
        return;
    }
    node* cur = *head;
    if(atEnd((*head)->next))return;
    while(!atEnd((cur->next)->next))cur = advance(cur);
    insertFront(head,&(cur->next));
    cur->next = NULL;
}

void delAlt(node** head){
    if(isEmpty(*head) || atEnd((*head)->next))
    	return;
    node* cur = *head;
    while(!atEnd(cur->next)){
    	node* temp = cur->next;
    	cur->next = temp->next;
    	free(temp);
    	if(cur->next == NULL)break;
    	cur = cur->next;
    }
}

void rotate(node** head, int k){
    k %= size(*head);
    if (k == 0) return;
    node* current = *head;
    int count = 1;
    while (count < k && current != NULL) {
        current = advance(current);
        count++;
    }
    if(current == NULL)
        return;
    node *kthNode = current;
    while(!atEnd(current->next))
        current = current->next;
    current->next = *head;
    *head = kthNode->next;
    kthNode->next = NULL;
}

void delList(node** head){
    while(!atEnd(*head)){
        node* temp = *head;
        *head = advance(*head);
        free(temp);
    }
}

void reverse(node** head){
    node *cur, *nex, *pre;
    cur = *head; pre = NULL;
    while(!atEnd(cur)){
        nex = cur->next;
        cur->next =pre;
        pre = cur;
        cur = nex;
    }
    *head = pre;
}
