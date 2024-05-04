#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char** argv) {
int i,j,N,TAT[10],WT[10],pos,temp;
 int Sum_wt=0,Sum_tat=0,AT[10],BT[10],PR[10];
 printf("Enter Total Process:\t ");
 scanf("%d",&N);
 
 for(i=0;i<N;i++)
 {
   printf("Enter Arrival Time for Process  %d :",i+1);
   scanf("%d",&AT[i]);
   printf("Enter Burst Time for Process  %d :",i+1);
   scanf("%d",&BT[i]);
   printf("Enter Priority of Process  %d :",i+1);
   scanf("%d",&PR[i]);
 }
 
 //Sort the processes according to priority
  for(i=0;i<N;i++)
 {
     pos=i;
     for(j=i+1;j<N;j++)
     {
         if(PR[j]<PR[pos])
         {
             pos=j;
         }
     }
     temp=PR[i];
     PR[i]=PR[pos];
     PR[pos]=temp;
     temp=BT[i];
     BT[i]=BT[pos];
     BT[pos]=temp;
 }
 
 //To find turnaround time and waiting time
 WT[0]=0;
 printf("Process\t AT\t BT \t PR\t TAT\tWT\n");
 for(i=0;i<N;i++)
 {
     WT[i]=0;
     TAT[i]=0;
     for(j=0;j<i;j++)
     {
         WT[i]=WT[i]+BT[j];
     }
     TAT[i]=WT[i]+BT[i];
     Sum_wt=Sum_wt+WT[i];
     Sum_tat=Sum_tat+TAT[i];
      printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,AT[i],BT[i],PR[i],TAT[i],WT[i]);
 }
  printf("\nAverage Waiting Time= %f\n",(Sum_wt*1.0)/N);
 printf("Avg Turnaround Time = %f\n\n",(Sum_tat*1.0)/N);
   return (EXIT_SUCCESS);
}