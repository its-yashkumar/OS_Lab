#include<stdio.h>
#include<stdlib.h>
int main(){
    int * block_size,*process_size,block_no,process_no,* flags,* alloc,i,j;
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
        scanf("%d",&process_size[i]);
    }
}