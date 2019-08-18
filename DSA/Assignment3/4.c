#include<stdio.h>
int size; //global variable to store size of the list

int list[100000];

int isEmpty();
int length();
int dataAt(int n);
void insert(int val,int n);
void delete(int n);
void print();
int search(int key);
void merge(int s,int m,int e);
void sort(int l,int r);

int main(){
    printf("Lets play list\n\n");
    printf("Enter the following numbers to do the corresponding operations\n\n");
    printf("1 to check whether the list is Empty\n");
    printf("2 to find the length of the list\n");
    printf("3,n to find the nth value of the list\n");
    printf("4,n,data to insert data at nth position of the list\n");
    printf("5,n to delete at nth position of the list\n");
    printf("6,key to search key in the list\n");
    printf("7 to sort the list\n");
    printf("X to terminate the program\n\n");
    int type;
    while(scanf("%d",&type)){
        int n,key,data;
        switch(type){
            case 1:
                if(isEmpty())printf("The list is empty\n");
                else printf("The list is not empty\n");
                break;
            case 2:
                printf("%d\n", length());
                break;
            case 3:
                scanf(",%d",&n);
                printf("%d\n",dataAt(n));
                break;
            case 4:
                scanf(",%d,%d",&n,&data);
                insert(data,n);
                break;
            case 5:
                scanf(",%d",&n);
                delete(n);
                break;
            case 6:
                scanf(",%d",&key);
                printf("%d\n",search(key));
                break;
            case 7:
                sort(0,size-1);
                break;
            default:
                break;
        }
        printf("The list at the current situation:\n");
        print();
        printf("\n");
    }
}

int isEmpty(){
  return (size?0:1);
}

int length(){
  return size;
}

int dataAt(int n){
  if(n>=size){
    printf("No data at %d\n", n);
    return 0;
  }
  return list[n];
}

void insert(int val,int n){
  if(n>size){
    printf("%d is not a valid position to insert\n", n);
    return;
  }
  int i;
  for(i=size-1;i>=n;i--){
    list[i+1] = list[i];  //shifting list towards right
  }
  list[n] = val;
  size++;
}

void delete(int n){
  int i;
  for(i=n;i<size;i++){
    list[i] = list[i+1];  //shifting list towards left
  }
  size--;
}

int search(int key){
    //using sentinel
    list[size] = key;
    int i=0;
    while(list[i]!=key)i++;
    if(i != size)return i;
    return -1;
}

void print(){
  int i;
  for(i=0;i<size;i++)
    printf("%d ", list[i]);
  printf("\n");
}

void merge(int s,int m,int e){
  int i=0,j=0,k=s;
  int l[m-s+1],r[e-m];
  for(i=0;i<m-s+1;i++)l[i]=list[s+i];
  for(i=0;i<e-m;i++)r[i]=list[m+i+1];
  i=0;
  while(i<m-s+1 && j<e-m){
    if(l[i]<=r[j]){
      list[k] = l[i];
      i++;k++;
    }
    else{
      list[k] = r[j];
      j++;k++;
    }
  }
  while(i<m-s+1){list[k] = l[i];i++;k++;}
  while(j<e-m){list[k] = r[j];j++;k++;}
}

void sort(int l,int r){
  if(l<r){
    int m = (l+r)/2;
    sort(l,m);
    sort(m+1,r);
    merge(l,m,r);
  }
}
