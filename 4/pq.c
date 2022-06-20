#include<stdio.h>
int main()
{ 
    int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,burst=0,pri[10];
    int bt[10],temp,temp1,j,at[10],wt[10],rt[10],tt[10],ta=0,sum=0;
    float wavg,tavg,tsum,wsum;
    printf("enter the No. processes ");
    scanf("%d",&n);
     printf("enter the arrival time, burst time and priority\n ");
    for(i=0;i<n;i++) {
   
    scanf("%d %d %d",&at[i], &bt[i], &pri[i]);
   
    }
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
    if(at[i]<at[j])/*sorting acc to arrival time*/
    {
    temp=p[j];
    p[j]=p[i];
    p[i]=temp;
    temp=at[j];
    at[j]=at[i];
    at[i]=temp;
    temp1=bt[j];
    bt[j]=bt[i];
    bt[i]=temp1;
    }
    }
    }
    for(j=0;j<n;j++)
    { burst=burst+bt[j];
    min=bt[k];
    for(i=k;i<n;i++)/*main logic*/
    { 
        min=pri[k];
        if (burst>=at[i])
        {
        if(pri[i]<min)
        {
            temp=p[k];
            p[k]=p[i];
            p[i]=temp;
            temp=at[k];
            at[k]=at[i];
            at[i]=temp;
            temp1=bt[k];
            bt[k]=bt[i];
            bt[i]=temp1;
            temp=pri[k];
            pri[k]=pri[i];
            pri[i]=temp;

        }
    }
    }
    k++;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        sum=sum+bt[i-1];
        wt[i]=sum-at[i];
    }
    for(i=0;i<n;i++)
    {
        wsum=wsum+wt[i];
    }
    wavg=wsum/n;
    for(i=0;i<n;i++)
    {
        ta=ta+bt[i];
        tt[i]=ta-at[i];
    }
    for(i=0;i<n;i++)
    {
        tsum=tsum+tt[i];
    }
    tavg=tsum/n;
    for(i=0;i<n;i++)
    {
        rt[i]=wt[i];
    }

    printf("************************");
    printf("\n RESULT:-\t\t\t VARIOUS TIMES");
    printf("\nprocess\t burst\t arrival\tpriority " );
    for(i=0;i<n;i++)
    {
        printf("\n p%d",p[i]);
        printf("\t %d",bt[i]);
        printf("\t %d",at[i]);
        printf("\t\t %d",pri[i]);
    }
    printf("\nwaiting time\tturnaround time\tresponce time");
    for(i=0;i<n;i++)
    {
        printf("\n %d",wt[i]);
        printf("\t\t %d",tt[i]);
        printf("\t\t%d",rt[i]);
    }
    printf("\nAVERAGE WAITING TIME:- %f ms",wavg);
    printf("\nAVERAGE TURN AROUND TIME:- %f ms" ,tavg);
    printf("\nAVERAGE RESPONSE TIME:- %f ms\n",wavg);
    }