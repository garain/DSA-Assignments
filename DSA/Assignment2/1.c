#include<stdio.h>
#include<math.h>
#define M 100000
long cnt;
typedef struct{
  float coef;
  int expo;
} term;

term hdd[M];

typedef struct{
  int st;
  int en;
} poly;

poly store(float c[],int e[],int n);
poly add(poly p,poly q);
poly mul(poly p,poly q);
void print(poly p);
poly scan();
poly save();

int main(){
  cnt=0;
  poly pol1,pol2;
  pol1 = save();
  pol2 = save();
  poly p3 = mul(pol1,pol2);
  //int i;
  //for(i=0;i<cnt;i++)printf("%f %d\n",hdd[i].coef,hdd[i].expo);
  printf("\n");
  print(pol1);
  print(pol2);
  print(p3);
  return 0;
}

void print(poly p){
  int i;
  for(i=p.st;i<=p.en;i++){
    if(hdd[i].coef>=0)printf("+ ");
    else printf("- ");
    printf("%fx^%d ", fabs(hdd[i].coef), hdd[i].expo);
  }
  printf("\n");
}

poly save(){
  poly p;
  p.st = cnt;
  printf("Enter the size of polynomial\n");
  int n;scanf("%d", &n);
  printf("Write down the polynomial\n");
  int i;
  for(i=0;i<n;i++){
    float co;int ex;
    scanf("%fx^%d", &co, &ex);
    hdd[cnt].coef = co;
    hdd[cnt].expo = ex;
    cnt++;
  }
  p.en = cnt-1;
  return p;
}

poly scan(){
  printf("Enter the size of polynomial\n");
  int n;scanf("%d", &n);
  float c[n];int e[n];
  printf("Write down the polynomial\n");
  int i;
  for(i=0;i<n;i++){
    char a;float b;int x;
    scanf("%fx^%d", &b, &x);
    c[i] = b;
    e[i] = x;
  }
  return store(c,e,n);
}

poly store(float c[],int e[],int n){
  poly p;
  p.st = cnt;
  for(int i=0;i<n;i++){
    hdd[cnt].coef = c[i];
    hdd[cnt].expo = e[i];
    cnt++;
  }
  p.en = cnt-1;
  return p;
}

poly add(poly p,poly q){
  poly res;
  res.st = cnt;
  int i=p.st, j=q.st;
  while(i!=p.en+1 && j!=q.en+1){
    if(hdd[i].expo > hdd[j].expo){
      hdd[cnt].expo = hdd[i].expo;
      hdd[cnt].coef = hdd[i].coef;
      i++;
    }
    else if(hdd[i].expo < hdd[j].expo){
      hdd[cnt].expo = hdd[j].expo;
      hdd[cnt].coef = hdd[j].coef;
      j++;
    }
    else{
      hdd[cnt].expo = hdd[j].expo;
      hdd[cnt].coef = hdd[i].coef + hdd[j].coef;
      i++;j++;
    }
    cnt++;
  }
  int k=0;
  if(i!=p.en+1 && j==q.en+1){
    for(k=i;k<=p.en;k++){
      hdd[cnt].expo = hdd[k].expo;
      hdd[cnt].coef = hdd[k].coef;
      cnt++;
    }
  }
  else if(i==p.en+1 && j!=q.en+1){
    for(k=j;k<=q.en;k++){
      hdd[cnt].expo = hdd[k].expo;
      hdd[cnt].coef = hdd[k].coef;
      cnt++;
    }
  }
  res.en = cnt-1;
  return res;
}

poly mul(poly p,poly q){
  int i,j;poly pp;
  pp.st = cnt;
  term mul[p.en-p.st+1][q.en-q.st+1],prev;
  for(i=p.st;i<=p.en;i++){
    for(j=q.st;j<=q.en;j++){
      hdd[cnt].coef = hdd[i].coef*hdd[j].coef;
      hdd[cnt].expo = hdd[i].expo+hdd[j].expo;
      if(prev.expo == hdd[cnt].expo){
        hdd[cnt-1].coef += hdd[cnt].coef;
        cnt--;
      }
      prev = hdd[cnt];
      cnt++;
    }
  }
  pp.en = cnt-1;
  return pp;
}
