#include<stdio.h>
int Qcounter=0;
int Pcounter=0;
 typedef struct
{
  int i;
  int j;
  float value;
}mat;

 typedef struct
{
  int begin;
  int end;
  int m;
  int n;
}find;

mat P[120*1200];

find Q[120];
void Sort(int n)
{
  int x,y;
  int Pi,Pj;
  double Pvalue;
  for(x=Q[n-1].begin;x<=Q[n-1].end;x++)
  {
    for(y=x;y>Q[n-1].begin;y--)
    {
      if(P[y].i<P[y-1].i)
      {
        Pi=P[y-1].i;
        Pj=P[y-1].j;
        Pvalue=P[y-1].value;
        P[y-1].i=P[y].i;
        P[y-1].j=P[y].j;
        P[y-1].value=P[y].value;
        P[y].i=Pi;
        P[y].j=Pj;
        P[y].value=Pvalue;
      }
    }
  }
    int ibegin=Q[n-1].begin;
    int iend;
    int x1;
    while(ibegin<Q[n-1].end){
    for(x1=ibegin;x1<=Q[n-1].end;x1++)
    {
      if(P[x1].i!=P[x1+1].i)
      {
        iend=x1;
        break;
      }
    }
      for(x=ibegin;x<=iend;x++)
      {
        for(y=x;y>ibegin;y--)
        {
          if(P[y].j<P[y-1].j)
          {
            //Pi=P[y-1].i;
            Pj=P[y-1].j;
            Pvalue=P[y-1].value;
            //P[y-1].i=P[y].i;
            P[y-1].j=P[y].j;
            P[y-1].value=P[y].value;
          //  P[y].i=Pi;
            P[y].j=Pj;
            P[y].value=Pvalue;
          }
        }
      }

    ibegin=iend+1;}



}
void AddMat(int first,int second)
{
  int fb,fe,sb,se,fm,fn,sm,sn;
  fb=Q[first-1].begin;
  fe=Q[first-1].end;
  sb=Q[second-1].begin;
  se=Q[second-1].end;
  fm=Q[first-1].m;
  fn=Q[first-1].n;
  sm=Q[second-1].m;
  sn=Q[second-1].n;
  if(fm==sm && fn==sn )
  {
    Q[Qcounter].begin=Pcounter;
    Q[Qcounter].m=fm;
    Q[Qcounter].n=fn;
    printf("Addition gives :) \n");
    //int breakmsg=0;
    for(int x=0;x<fm;x++)
    {
      for(int y=0;y<fn;y++)
      { int dectfirst=0;
        int dectsecond=0;
        int z,u;
        for(z=fb;z<=fe;z++)
          {
            if(x==P[z].i && y==P[z].j)
            {dectfirst=1;
            break;}
          }
        for(u=sb;u<=se;u++)
          {
            if(x==P[u].i && y==P[u].j)
            {dectsecond=1;
            break;}
          }
          if(dectfirst==1&&dectsecond==1)
          {
            P[Pcounter].i=x;
            P[Pcounter].j=y;
            P[Pcounter].value=P[z].value+P[u].value;
            printf("%d %d %f\n", P[Pcounter].i,P[Pcounter].j,P[Pcounter].value);
            Pcounter++;
          }
          else if(dectfirst==1)
          {
            P[Pcounter].i=x;
            P[Pcounter].j=y;
            P[Pcounter].value=P[z].value;
              printf("%d %d %f\n", P[Pcounter].i,P[Pcounter].j,P[Pcounter].value);
            Pcounter++;
          }
          else if(dectsecond==1)
          {
            P[Pcounter].i=x;
            P[Pcounter].j=y;
            P[Pcounter].value=P[u].value;
              printf("%d %d %f\n", P[Pcounter].i,P[Pcounter].j,P[Pcounter].value);
            Pcounter++;
          }

        }
      }
      Q[Qcounter].end=Pcounter-1;
      Qcounter++;
    }

  else
  printf("Addition is not possible :-(\n");
}

void SubMat(int first,int second)
{
  int fb,fe,sb,se,fm,fn,sm,sn;
  fb=Q[first-1].begin;
  fe=Q[first-1].end;
  sb=Q[second-1].begin;
  se=Q[second-1].end;
  fm=Q[first-1].m;
  fn=Q[first-1].n;
  sm=Q[second-1].m;
  sn=Q[second-1].n;
  if(fm==sm && fn==sn )
  {
    Q[Qcounter].begin=Pcounter;
    Q[Qcounter].m=fm;
    Q[Qcounter].n=fn;
    printf("Subtraction gives :) \n");
    //int breakmsg=0;
    for(int x=0;x<fm;x++)
    {
      for(int y=0;y<fn;y++)
      { int dectfirst=0;
        int dectsecond=0;
        int z,u;
        for(z=fb;z<=fe;z++)
          {
            if(x==P[z].i && y==P[z].j)
            {dectfirst=1;
            break;}
          }
        for(u=sb;u<=se;u++)
          {
            if(x==P[u].i && y==P[u].j)
            {dectsecond=1;
            break;}
          }
          if(dectfirst==1&&dectsecond==1)
          {
            if(P[z].value-P[u].value!=0){
            P[Pcounter].i=x;
            P[Pcounter].j=y;
            P[Pcounter].value=P[z].value-P[u].value;
            printf("%d %d %f\n", P[Pcounter].i,P[Pcounter].j,P[Pcounter].value);
            Pcounter++;
            }
          }
          else if(dectfirst==1)
          {
            P[Pcounter].i=x;
            P[Pcounter].j=y;
            P[Pcounter].value=P[z].value;
              printf("%d %d %f\n", P[Pcounter].i,P[Pcounter].j,P[Pcounter].value);
            Pcounter++;
          }
          else if(dectsecond==1)
          {
            P[Pcounter].i=x;
            P[Pcounter].j=y;
            P[Pcounter].value=-P[u].value;
              printf("%d %d %f\n", P[Pcounter].i,P[Pcounter].j,P[Pcounter].value);
            Pcounter++;
          }

        }
      }
      Q[Qcounter].end=Pcounter-1;
      Qcounter++;
    }

  else
  printf("Subtraction is not possible :-(\n");
}

void Transpose(int n, int prt)
{

  int beg=Q[n-1].begin;
  int end=Q[n-1].end;
  Q[Qcounter].begin=Pcounter;
  Q[Qcounter].m=Q[n-1].n;
  Q[Qcounter].n=Q[n-1].m;
  if(prt==1) printf("After Transpose :\n" );
  for(int x=beg;x<=end;x++)
  {
    P[Pcounter].i=P[x].j;
    P[Pcounter].j=P[x].i;
    P[Pcounter].value=P[x].value;
    Pcounter++;

  }
  Q[Qcounter].end=Pcounter-1;
  Qcounter++;
  Sort(Qcounter);
  if(prt==1)
  {
    for(int x=Q[Qcounter-1].begin;x<=Q[Qcounter-1].end;x++)
    {
      printf("%d %d %f\n",P[x].i,P[x].j,P[x].value );
    }
  }
}

void MultMat( int first, int second)
{
  //Sort(first-1);
  int fb,fe,sb,se,fm,fn,sm,sn;
  fb=Q[first-1].begin;
  fe=Q[first-1].end;
  fm=Q[first-1].m;
  fn=Q[first-1].n;
  Transpose(second,0);
  //int g=Qcounter-1;
  sb=Q[Qcounter-1].begin;
  se=Q[Qcounter-1].end;
  sm=Q[Qcounter-1].m;
  sn=Q[Qcounter-1].n;
  //printf("%d %d\n",fn,sn );
  if(fn==sn)
  {
    Q[Qcounter].begin=Pcounter;
    printf("Multiplication gives :\n" );
    int x=0;
    for(int x=0;x<fm;x++)
    {

    for(int y=0;y<sm;y++)
    {
      float sum=0;

      int t,s;
        for(int k=0;k<fn;k++)
        {  int dectfirst=0;
          int dectsecond=0;
          for(s=fb;s<=fe;s++)
          {
            if(P[s].i==x && P[s].j==k)
            {dectfirst=1;break;}
          }
          for(t=sb;t<=se;t++)
          {
            if(P[t].i==y && P[t].j==k)
            {
              dectsecond=1;break;
            }
          }
          if(dectfirst==1 && dectsecond==1)
          {
            sum=sum+P[t].value*P[s].value;
            //printf("(%d ,%d) and (%d, %d) and (%f * % f)\n",P[s].i,P[s].j,P[t].i,P[t].j,P[s].value,P[t].value );
            dectfirst=0;
            dectsecond=0;
          }


        }
        if(sum!=0)
        {
          P[Pcounter].value=sum;
          P[Pcounter].i=x;
          P[Pcounter].j=y;
          printf("%d %d %f\n", P[Pcounter].i,P[Pcounter].j,P[Pcounter].value);
          Pcounter++;
        }
      }
    }
    Q[Qcounter].end=Pcounter-1;
    Q[Qcounter].m=fm;
    Q[Qcounter].n=sm;
    Qcounter++;
  }
  else
  {
    printf("Multiplication not possible :-(\n" );
  }
}

int main(void)
{
  for(int x=0;x<120*1200;x++)
  {
    int row;
    int column;
    printf("Enter the no. of rows : ");
    scanf("%d",&row);
    printf("Enter the no. of columns : ");
    scanf("%d",&column);
    if(row>0 && column>0)
    {
      Q[Qcounter].begin=Pcounter;
      Q[Qcounter].m=row;
      Q[Qcounter].n=column;
      printf("Enter <i> <spcae> <j> <space> <value> and press negative for new matrix : \n");
      printf("where 0<=i<=m-1 and 0<=j<=n-1 and value>0 , invalid input will start inputting new matrix :\n" );
      while(1)
      {
        int a,b;
        float no;
        scanf("%d",&a);
        if(a>=0 && a<row)
        {
          scanf("%d",&b);
          if(b>=0 && b<column)
          {
            scanf("%f",&no);
            if(no!=0)
            {
              P[Pcounter].i=a;
              P[Pcounter].j=b;
              P[Pcounter].value=no;
              Pcounter++;
            }
            else
            {
              Q[Qcounter].end=Pcounter-1;
              Qcounter++;
              break;
            }

          }
          else
          {
            Q[Qcounter].end=Pcounter-1;
            Qcounter++;
            break;
          }
        }
        else
        {
          Q[Qcounter].end=Pcounter-1;
          Qcounter++;
          break;
        }
      }

    }
    else
    break;
  }
  
  printf("What are the two sparse matrices you want to add ?\n" );
  int first,second;
  scanf("%d %d",&first,&second );
  AddMat(first,second);

  printf("What are the two sparse matrices you want to subtract ?\n" );
//  int first,second;
  scanf("%d %d",&first,&second );
  SubMat(first,second);
  //Sort(1);
printf("Enter the number of matrix, you want to transpose : \n");
int p;
scanf("%d",&p );
Transpose(p,1);

printf("What are the two sparse matrices you want to multiply ?\n" );
//  int first,second;
scanf("%d %d",&first,&second );
MultMat(first,second);
printf("\n" );
printf("First 50 elements of the whole Sparse Mat pool are here ;-) :\n");
  for(int x=0;x<50;x++)
  {
    printf("%d ",P[x].i);
    printf("%d ",P[x].j);
    printf("%f\n",P[x].value);
  }

  printf("\n");
printf("First 50 elements of the whole index pool are here ;-) :\n");
  for(int x=0;x<50;x++)
  {
    printf("%d ",Q[x].begin);
    printf("%d ",Q[x].end);
    printf("%d ",Q[x].m);
    printf("%d\n",Q[x].n);
  }
}
