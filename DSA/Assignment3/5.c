#include<stdio.h>
#include<stdlib.h>


typedef struct ndd{
    int data;
    struct ndd* prev;
    struct ndd* next;
} doub;

typedef struct ndc{
    int data;
    struct ndc* next;
} circ;

doub* getNode(int data){
    doub* temp;
    if((temp = (doub* )malloc(sizeof(doub))) == NULL){
        printf("Allocation Error\n");
        return NULL;
    }
    else temp->data = data;
    return temp;
}

circ* getCirc(int data){
    circ* temp;
    if((temp = (circ* )malloc(sizeof(circ))) == NULL){
        printf("Allocation Error\n");
        return NULL;
    }
    else temp->data = data;
    return temp;
}

void insertFront(doub** head,doub* target){
    if(*head == NULL){
        *head = target;
        target->prev = NULL;
        target->next = NULL;
        return;
    }
    doub* cur = *head;
    target->prev = NULL;
    target->next = cur;
    cur->prev = target;
    *head = target;
}

void appendCirc(circ** head, circ* target){
    if(*head == NULL){
        *head = target;
        target->next = *head;
        return;
    }
    circ* cur = *head;
    while(cur->next != *head)cur = cur->next;
    cur->next = target;
    target->next = *head;
}

void printFront(doub* head){
    while (head != NULL) {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void printRev(doub* head){
    while(head->next != NULL)head = head->next;
    while (head != NULL) {
        printf("%d ",head->data);
        head = head->prev;
    }
    printf("\n");
}

void printCirc(circ* head){
    if(head == NULL){
        printf("\n");
        return;
    }
    circ* stop = head;
    do{
        printf("%d ",head->data);
        head = head->next;
    }while(stop != head);
    printf("\n");
}

int main(){
    circ* list;
    list = NULL;
    int i;
    for(i=0;i<5;i++){
        circ* t = getCirc(i);
        appendCirc(&list,t);
    }
    printCirc(list);
    //printRev(list);
    return 0;
}
