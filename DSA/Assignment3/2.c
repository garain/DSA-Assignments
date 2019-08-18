#include<stdio.h>
#include<stdlib.h>
#include "header.c"

void print(node* head);

int main(){
    FILE* fp = fopen("abc.txt","r");
    node *inOrd, *revOrd, *cur;
    init(&inOrd);init(&revOrd);int x,i=0;
    while(!feof(fp)){
        fscanf(fp,"%d\n",&x);
        node* temp1 = getNode(x);node* temp2 = getNode(x);
        if(i==0){
            insertFront(&inOrd,&temp1);
            cur = inOrd;
        }
        else{
            insertAfter(&inOrd,&cur,&temp1);
            cur = advance(cur);
        }
        insertFront(&revOrd,&temp2);i++;
    }
    print(inOrd);
    print(revOrd);
    fclose(fp);
    return 0;
}

void print(node* head){
    while(!atEnd(head)){
        printf("%d ",head->data);
        head = advance(head);
    }
    printf("\n");
}
