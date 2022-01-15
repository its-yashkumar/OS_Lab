#include<stdio.h>
#include<stdlib.h>

struct process_input
{
	int process_no;
	float arrive_t;
	float burst_t;
	float comp_t;
	float temp_bt;
	float turn_ard_t;
	float wait_t;
	int prio;
};

void display(struct process_input process_ip[]);
void fcfs(struct process_input process_ip[]);
void sjf_nonpreemptive(struct process_input process_ip[]);
void priority_nonpreemptive(struct process_input process_ip[]);
void sjf_preemptive(struct process_input process_ip[]);
void priority_preemptive(struct process_input process_ip[]);
void round_robin(struct process_input process_ip[]);

int num_of_pr;

int main()
{
    int i,choice;
    printf("Enter the number of processes: ");
    scanf("%d",&num_of_pr);
    struct process_input *process_ip,*temp;
    process_ip=(struct process_input*)malloc(num_of_pr*sizeof(struct process_input));
    temp=(struct process_input*)malloc(num_of_pr*sizeof(struct process_input));
    
    for(i=0;i<num_of_pr;i++)
    {
        process_ip[i].process_no=i+1;
        printf("\nEnter the arival time of process P%d: ",i+1);
        scanf("%f",&process_ip[i].arrive_t);
        printf("\nEnter the burst time of process P%d: ",i+1);
        scanf("%f",&process_ip[i].burst_t);
        printf("\nEnter the priority of process P%d: ",i+1);
        scanf("%d",&process_ip[i].prio);
        process_ip[i].temp_bt=process_ip[i].burst_t;
        process_ip[i].comp_t=0;   
        process_ip[i].turn_ard_t=0;
        process_ip[i].wait_t=0;
    }
		for(i=0;i<num_of_pr;i++)
		{
		    temp[i]=process_ip[i];
		}
    do{
        
        for(i=0;i<num_of_pr;i++)
        {
            process_ip[i]=temp[i];
        }
        printf("\nSelect the type of scheduling\n0.Exit\n");
        printf("1.First come first serve(fcfs)\n");
        printf("2.Shortest Job First(Non-Preemptive)\n");
        printf("3.Priority Sheduling(Non-Preemptive)\n");
        printf("4.Shortest Job First(Preemptive)\n");
        printf("5.Priority Sheduling(Preemptive)\n");
        printf("6.Round Robin\n");
        scanf("%d",&choice);
       
        switch(choice)
        {
            case 1:fcfs(process_ip);
            break;
            case 2:sjf_nonpreemptive(process_ip);
            break;
            case 3:priority_nonpreemptive(process_ip);
            break;
            case 4:sjf_preemptive(process_ip);
            break;
            case 5:priority_preemptive(process_ip);
            break;
            case 6:round_robin(process_ip);
            break;
        }
    
    }while(choice);
}

void display(struct process_input process_ip[])
{
	int i;
    float turn_ard_t=0,avg_wait_t=0;
    printf("pro no \t| \t arrival \t| \t burst time \t| \t TAT \t\t| \t AWT \n");
    for(i=0;i<num_of_pr;i++)
    {
        process_ip[i].turn_ard_t=process_ip[i].comp_t-process_ip[i].arrive_t;
        process_ip[i].wait_t=process_ip[i].turn_ard_t-process_ip[i].burst_t;
    printf("%d\t|\t%f\t|\t%f\t|\t%f\t|\t%f\n",process_ip[i].process_no,process_ip[i].arrive_t,process_ip[i].burst_t,process_ip[i].turn_ard_t,process_ip[i].wait_t);
    }
    printf("\n");
    for(i=0;i<num_of_pr;i++)
    {
        turn_ard_t=turn_ard_t+process_ip[i].turn_ard_t;
        avg_wait_t=avg_wait_t+process_ip[i].wait_t;
    }   
    printf("Average Turn Arround Time :: %f\n",turn_ard_t/num_of_pr);
    printf("Average Waiting Time :: %f\n",avg_wait_t/num_of_pr);
    printf("\n"); 
}

void fcfs(struct process_input process_ip[])
{
	int i,j,po,c_pro,total=0,time=0;
    struct process_input temp;
    for(i=0;i<num_of_pr-1;i++)
    {
        for(j=0;j<num_of_pr-i-1;j++)
        {        
            if(process_ip[i].arrive_t>process_ip[i+1].arrive_t)
            {
                temp=process_ip[i];
                process_ip[i]=process_ip[i+1];
                process_ip[i+1]=temp;
            }
        }
    }
    
    for(i=0;i<num_of_pr;i++)
    {
        total=total+process_ip[i].burst_t;
    }
   	c_pro=0;   
    printf("|0|  ");
    while(1)
    {
    if(c_pro!=po)
    {
    	printf("P%d  |%d|  ",po+1,time);
    }
   
    process_ip[c_pro].temp_bt--;
    po=c_pro;
    if(process_ip[c_pro].temp_bt == 0)
    {
        process_ip[c_pro].comp_t=time+1;
        c_pro++;
    }       
    time++;
    if(time==total)
    {
        printf("P%d  |%d|",c_pro,time);
        break;
    }    
    }
    printf("\nFirst come first serve\n");
    display(process_ip);
}

void sjf_nonpreemptive(struct process_input process_ip[])
{
	int n,i,time=0,total=0,c_pro,j,po;
    struct process_input temp;
    for(i=0;i<num_of_pr-1;i++)
    {
        for(j=0;j<num_of_pr-i-1;j++)
        {        
            if(process_ip[i].arrive_t>process_ip[i+1].arrive_t)
            {
                temp=process_ip[i];
                process_ip[i]=process_ip[i+1];
                process_ip[i+1]=temp;
            }
        }
    }
     
    for(i=0;i<num_of_pr;i++)
    {
        total=total+process_ip[i].burst_t;
        printf("%d\t%f\t%f\n",i+1,process_ip[i].arrive_t,process_ip[i].burst_t);
    }
    
    c_pro=0;
    printf("|0|  ");
    while(1){
    for(n=0;process_ip[n].arrive_t<=time && n<num_of_pr;n++);
    po=c_pro;
    if(process_ip[c_pro].temp_bt == 0)
    {
        for(i=0;i<n;i++)
        {
            if(process_ip[i].temp_bt!=0)
            {
                c_pro=i;
                break;
            }
        }
        for(i=0;i<n;i++)
        {
            if((process_ip[c_pro].temp_bt>process_ip[i].temp_bt) && process_ip[i].temp_bt!=0)
                c_pro=i;
        }
    }
    
    if(c_pro!=po)
    {
    	printf("P%d  |%d|  ",po,time);
    }
    process_ip[c_pro].temp_bt--;
    if(process_ip[c_pro].temp_bt == 0)
    {
        process_ip[c_pro].comp_t=time+1;
    }
    time++;
    if(time==total)
    {
        printf("P%d  |%d|\n\n",c_pro,time);
        break;
    }
    }
    printf("\nShortest job First(non-preemptive)\n");
    display(process_ip);
}

void priority_nonpreemptive(struct process_input process_ip[])
{
	int n,i,time=0,total=0,c_pro,j,po;
    struct process_input temp;
    for(i=0;i<num_of_pr-1;i++)
    {
        for(j=0;j<num_of_pr-i-1;j++)
        {        
            if(process_ip[i].arrive_t>process_ip[i+1].arrive_t)
            {
                temp=process_ip[i];
                process_ip[i]=process_ip[i+1];
                process_ip[i+1]=temp;
            }
        }
    }
     
    for(i=0;i<num_of_pr;i++)
    {
        total=total+process_ip[i].burst_t;
    }
    c_pro=0;
    printf("|0|  ");
    while(1)
    {
    	if(c_pro!=po)
    	{
    		printf("P%d  |%d|  ",po+1,time);
    	}
    	for(n=0;process_ip[n].arrive_t<=time && n<num_of_pr;n++);
    	if(process_ip[c_pro].temp_bt==0)
    	{
        	for(i=0;i<n;i++)
        	{
            	if(process_ip[i].temp_bt!=0)
            	{
                	c_pro=i;
                	break;
            	}	
        	}
        	for(i=0;i<n;i++)
        	{
            	if((process_ip[c_pro].prio>process_ip[i].prio) && process_ip[i].temp_bt!=0)
            	{
            	    c_pro=i;
            	}
        	}
    	}
    	process_ip[c_pro].temp_bt--;
    	po=c_pro;
    
    	if(process_ip[c_pro].temp_bt == 0)
    	{
        	process_ip[c_pro].comp_t=time+1;
    	}
    	time++;
    	if(time==total)
    	{
        	printf("P%d  |%d|",c_pro,time);
        	break;
    	}
    }
    printf("\nPriority sheduling(non-preemptive)\n");
    display(process_ip);
}

void sjf_preemptive(struct process_input process_ip[])
{
	int i,j,time,n,c_pro,total=0,po;
    float tat;
    
    struct process_input temp;
    for(i=0;i<num_of_pr-1;i++)
    {
        for(j=0;j<num_of_pr-i-1;j++)
        {        
            if(process_ip[i].arrive_t>process_ip[i+1].arrive_t)
            {
                temp=process_ip[i];
                process_ip[i]=process_ip[i+1];
                process_ip[i+1]=temp;
            }
        }
    }
    
    for(i=0;i<num_of_pr;i++)
    {
        total=total+process_ip[i].burst_t;
    }
    printf("\n\n");
    time=0;
    c_pro=0;
    printf("|0|  ");
    while(1)
    {
    	for(n=0;process_ip[n].arrive_t<=time && n<num_of_pr;n++);
        po=c_pro;
        if(process_ip[c_pro].temp_bt !=0)
        {
        	for(i=0;i<n;i++)
        	{
            	if((process_ip[c_pro].temp_bt>process_ip[i].temp_bt) && process_ip[i].temp_bt!=0 )
                	c_pro=i;
        	}
    	}
    	else
    	{
        	for(i=0;i<n;i++)
        	{
        	    if(process_ip[i].temp_bt!=0)
        	    {
        	        c_pro=i;
        	        break;
        	    }
        	}
        	for(i=0;i<n;i++)
        	{
            	if((process_ip[c_pro].temp_bt>process_ip[i].temp_bt)&&process_ip[i].temp_bt!=0 )
            	    c_pro=i;
        	}
    	}
    	if(c_pro!=po)
    	{
    		printf("P%d  |%d|  ",po,time);
    	}
   
		process_ip[c_pro].temp_bt--;
		if(process_ip[c_pro].temp_bt==0)
		    process_ip[c_pro].comp_t=time+1;
		
		time++;
		if(time==total)
		{
		    printf("P%d  |%d|",c_pro,time);
		    break;
		}    
    }
     printf("\n\n");
     printf("\nShortest job First(preemptive)\n");
     display(process_ip);
}

void priority_preemptive(struct process_input process_ip[])
{
	int n,i,time=0,total=0,c_pro,j,po;
    struct process_input temp;
    for(i=0;i<num_of_pr-1;i++)
    {
        for(j=0;j<num_of_pr-i-1;j++)
        {        
            if(process_ip[i].arrive_t>process_ip[i+1].arrive_t)
            {
                temp=process_ip[i];
                process_ip[i]=process_ip[i+1];
                process_ip[i+1]=temp;
            }
        }
    }
     
    for(i=0;i<num_of_pr;i++)
    {
        total=total+process_ip[i].burst_t;
    }
    c_pro=0;
    printf("|0|  ");
    while(1)
    {
    	for(n=0;process_ip[n].arrive_t<=time && n<num_of_pr;n++);
    	po=c_pro;
    	if(process_ip[c_pro].temp_bt==0)
    	{
    	    for(i=0;i<n;i++)
    	    {
    	        if(process_ip[i].temp_bt!=0)
    	        {
    	            c_pro=i;
    	            break;
    	        }
    	    }
    	    for(i=0;i<n;i++)
    	    {
    	        if((process_ip[c_pro].prio>process_ip[i].prio) && process_ip[i].temp_bt!=0)
    	        {
    	            c_pro=i;
    	        }
    	    }
    	}
    	else
    	{
    	    for(i=0;i<n;i++)
    	    {
    	        if((process_ip[c_pro].prio>process_ip[i].prio) && process_ip[i].temp_bt!=0)
    	        {
    	            c_pro=i;
    	        }
    	    }
    	}
    	if(c_pro!=po)
    	{
    		printf("P%d  |%d|  ",po,time);
    	}
   		process_ip[c_pro].temp_bt--;
    	if(process_ip[c_pro].temp_bt == 0)
    	{
    	    process_ip[c_pro].comp_t=time+1;
    	}
    	time++;
    	if(time==total)
    	{
    	    printf("P%d  |%d|",c_pro,time);
    	    break;
    	}
    }
    
    printf("\nPriority sheduling(preemptive)\n");
    display(process_ip);
}

void round_robin(struct process_input process_ip[])
{
	int n=0,q,i,j,total=0,time=0,a[50],front=-1,rear=-1,n1=0,c,c_pro=0;
    struct process_input temp;
    
    printf("Enter the time Quantum: ");
    scanf("%d",&q);
    
    for(i=0;i<num_of_pr-1;i++)
    {
        for(j=0;j<num_of_pr-i-1;j++)
        {        
            if(process_ip[i].arrive_t>process_ip[i+1].arrive_t)
            {
                temp=process_ip[i];
                process_ip[i]=process_ip[i+1];
                process_ip[i+1]=temp;
            }
        }
    }
     
    for(i=0;i<num_of_pr;i++)
    {
        total=total+process_ip[i].burst_t;
    }
    
    while(1)
    {
    	n1=n;
    	for(n=0;process_ip[n].arrive_t<=time && n<num_of_pr;n++);
        	if(n-n1>0)
        	{
        	    if(front == -1)
        	    {
        	        front=0;
        	    }
        	    c=n-n1;
        	    while(c!=0)
        	    {
        	        rear++;
        	        a[rear]=n-c;
        	        c--;    
        	    }
        	}
    	c_pro=a[front];
    	front++;
    	
    	printf("|%d| P%d ",time,c_pro);
    	
    	if(process_ip[c_pro].temp_bt<=q)
    	{
    	    time=time+process_ip[c_pro].temp_bt;
    	    process_ip[c_pro].temp_bt=0;
    	    process_ip[c_pro].comp_t=time;
    	}
    	else
    	{
    	    time=time+q;
    	    process_ip[c_pro].temp_bt=process_ip[c_pro].temp_bt-q;
    	    rear++;
    	    a[rear]=c_pro;
    	}
    	if(time==total)
    	    break;
    }
    printf("|%d|",time);
    printf("\nRound Robin Sheduling\n");
    display(process_ip);
}
