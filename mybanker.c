#include<stdio.h>
int main()
{   
    int n, m, i, j, k, alloc[20][20], max[20][20], available[20];
    int f[20],ans[20], ind=0, need[20][20]; 
    
    
    printf("Enter number of processes: ");
    scanf("%d",&n);
    
    
    printf("Enter the number of Resources: ");
    scanf("%d",&m);
    
    
    printf("Enter the Values of Allocation Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter value at position (%d%d) :",i+1,j+1);
            scanf("%d",&alloc[i][j]);
        }
    }
    
    
        printf("Enter the Values of Max Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter value at position (%d%d) :",i+1,j+1);
            scanf("%d",&max[i][j]);
        }
    }
    
    
    printf("Enter the values in available: \n");
    for(j=0;j<m;j++)
    {
        printf("Enter value at position (%d) :",j+1);
        scanf("%d",&available[j]);
    }
    
   
    for(k=0;k<n;k++)
    {
        f[k]=0;
    }
    
    
    for(i=0;i<n;i++)   
    {
        for(j=0;j<m;j++)   
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
   
    int y=0;

    for(k=0;k<n;k++)    
    {
        for(i=0;i<n;i++)   
        {
            if(f[i]==0)     
            {
                int flag = 0;   
                for(j=0;j<m;j++)    
                {
                    if(need[i][j] > available[j])   
                    {
                        flag=1;
                       
                        break;
                    }
                }
                
                if(flag==0)
                {
                    ans[ind++] = i;
                    for(y=0;y<m;y++)    
                    {
                        available[y] = available[y] + alloc[i][y];   
                    }
                    f[i]=1; 
                }
            }
        }
    }
    
    printf("The SAFE SEQUENCE is: \n");
    for(i=0;i<n-1;i++) 
    {
        printf(" P%d ->", ans[i]);
    }
    printf(" P%d", ans[n-1]);    
printf("\nIf you are getting garbage values anywhere then system is in unsafe state\n");
}
