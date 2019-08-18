#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;
/*
void init(node** head);
node* getNode(int data);
node* advance(node* temp);
int isEmpty(node* head);
int atEnd(node* cur);
void insertFront(node** head,node** target);
void insertAfter(node** head,node** prev,node** target);
void delFront(node** head);
void delAfter(node** head, node** prev);

int main(){
    node* h;init(&h);int i;
    for(i=0;i<5;i++){
        node* t = getNode(i);
        insertFront(&h,&t);
    }
    node* tt = getNode(100);
    insertAfter(&h,&h,&tt);
    delAfter(&h,&(h->next));
    node* temp = h;
    while(!atEnd(temp)){
        printf("%d\n",temp->data);
        temp = advance(temp);
    }
    return 0;
}
*/
void init(node** head){
    *head = NULL;
}

node* getNode(int data){
    node* temp;
    if((temp = (node* )malloc(sizeof(node))) == NULL){
        printf("Allocation Error!\n");
        return NULL;
    }
    temp->data = data;
    return temp;
}

node* advance(node* temp){
    return temp->next;
}

int isEmpty(node* head){
    return (head == NULL);
}

int atEnd(node* cur){
    return (cur == NULL);
}

void insertFront(node** head, node** target){
    (*target)->next = *head;
    *head = *target;
}

void insertAfter(node** head, node** prev, node** target){
    node* temp = *head;
    while(temp != *prev){
        temp = advance(temp);
    }
    (*target)->next = temp->next;
    temp->next = *target;
}

void delFront(node** head){
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delAfter(node** head, node** prev){
    if(!(*prev || (*prev)->next)){
        printf("Error\n");
        return;
    }
    node* temp = *head;
    while(temp != (*prev)->next){
        temp = advance(temp);
    }
    (*prev)->next = temp->next;
    free(temp);
}
