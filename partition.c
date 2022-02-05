#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
void FirstFit(int* block_size,int block_no,int * process_size,int process_no);
void BestFit(int* block_size,int block_no,int * process_size,int process_no);
int main(){
    int * block_size,*process_size,block_no,process_no,i,j;
    printf("Enter number of blocks\n");
    scanf("%d",&block_no);
    block_size=(int *)malloc(block_no*sizeof(int));
      for(i=0;i<block_no;i++){
        printf("Enter size of %d Block in KB\n",i);
        scanf("%d",&block_size[i]);
    }
    printf("Enter number of processes\n");
    scanf("%d",&process_no);
    process_size=(int *)malloc(process_no*sizeof(int));
    for(j=0;j<process_no;j++){
        printf("Enter size of %d process in KB\n",j);
        scanf("%d",&process_size[j]);
    }
    FirstFit(block_size,block_no,process_size,process_no);
    BestFit(block_size,block_no,process_size,process_no);
}
void FirstFit(int* block_size,int block_no,int * process_size,int process_no){
   int * alloc;
   alloc=(int *)malloc(process_no*sizeof(int));
   memset(alloc,-1,process_no*sizeof(alloc));
   for (int i = 0; i < process_no; i++)
   {
       for (int j = 0; j < block_no; j++)
       {
           if(block_size[j]>=process_size[i]){
               alloc[i]=j;
               block_size[j]=block_size[j]-process_size[i];
               break;
           }
       }
       
   }
  
   printf("\nProcess No |\tProcess Size |\tBlock No |\n");
   for (int i = 0; i < process_no; i++){
     printf(" %d",i+1);
     printf("\t\t %d",process_size[i]);
     printf("\t\t");
     if(alloc[i]!=-1){
         printf("%d\n",(alloc[i]+1));
     }
     else{
         printf("Not Allocated\n");
         fflush(stdin);
     }
   }
   
}
void BestFit(int* block_size,int block_no,int * process_size,int process_no){
   int * alloc;
   alloc=(int *)malloc(process_no*sizeof(int));
   memset(alloc,-1,process_no*sizeof(alloc));
   for (int i = 0; i < process_no; i++)
   {    int best=-1;
       for (int j = 0; j < block_no; j++)
       {
          
           if(block_size[j]>=process_size[i]){
              if(best==-1){
                  best=j;
              }
              else if(block_size[best]>block_size[j]){
                 best=j;
              }
           }
       }
       if(best != -1){
         alloc[i]=best;
         block_size[best]=block_size[best]-process_size[i];
       }
       
   }
    printf("\nProcess No |\tProcess Size |\tBlock No |\n");
   for (int i = 0; i < process_no; i++){
     printf(" %d",i+1);
     printf("\t\t %d",process_size[i]);
     printf("\t\t");
     if(alloc[i]!=-1){
         printf("%d\n",(alloc[i]+1));
     }
     else{
         printf("Not Allocated\n");
         fflush(stdin);
     }
   }
}