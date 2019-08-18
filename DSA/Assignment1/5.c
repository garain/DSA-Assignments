 #include<stdio.h>
 #include<string.h>
 struct student{
     int rno;
     int slno;
     char lname[15];
     char name[30];
 };
 void wrd_insrsnsrt(struct student arr[] , int n){
     int i, j;
     struct student t;
     for(i =1; i < n; i++){
         j = i - 1;
         t = arr[i];
         while(strcmp(t.name, arr[j].name)<0 && j>=0){
             arr[j+1] = arr[j];
             j--;
         }
         arr[j+1] = t;
     }
 }
 int main(void){
     char str[40], maxname[30], minname[30] = "Md Sahil" ;
     int i = 0, n, M, m;
     struct student s , arr[60];
     FILE *fp ;
     fp = fopen("JUCSEcopy2.txt","r");
     while(!feof(fp)){
         fscanf(fp,"%d\t%d\t%s %s\n",&s.slno,&s.rno,s.name,s.lname);
         //printf("%d\t%d\t%s %s\n",s.slno,s.rno,s.name,s.lname);
         strcat(s.name, " ");
         strcat(s.name,s.lname);
         if(strlen(maxname) <= strlen(s.name)){
            strcpy(maxname,s.name);
            M = strlen(s.name);
         }    
         if(strlen(minname) >= strlen(s.name)){
            strcpy(minname,s.name);
            m = strlen(s.name);
         } 
         arr[i] = s;
         i++;
        }
    fclose(fp);
    n = i + 1;
    fp = fopen("JUCSEsorted.txt", "w");
    wrd_insrsnsrt(arr, n);
    for(i=0; i < n ; i++){
        fprintf(fp, "%d %d %s\n", i, arr[i].rno , arr[i].name);
    
    }
    fclose(fp);
    printf("The largest name found is %s of length %d\n",maxname,M);
    printf("The smallest name found is %s of length %d\n",minname,m);
    return 0;
 }
