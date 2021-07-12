/*
    First Come First Serve Process Scheduling Algorithm
    (Non-Preemptive)
*/

#include <stdio.h>
#define MAX 100
void fcfs(int n, int at[], int bt[])
{
    int ct[n], wt[n], tat[n];
    float totalWT = 0, totalTAT = 0;
    
    ct[0] = at[0] + bt[0];
    
    for (int i = 1; i < n; i++)
        ct[i] = ct[i - 1] + bt[i];
    
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        totalTAT = totalTAT + tat[i];
        totalWT = totalWT + wt[i];
    }
    
    // Printing table
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i + 1);
        printf("\t%d ", at[i]);
        printf("\t%d ", bt[i]);
        printf("\t%d ", ct[i]);
        printf("\t%d", tat[i]);
        printf("\t%d\n", wt[i]);
    }
    printf("Average Turn around time = %f \n", totalTAT / n);
    printf("Average Waiting time = %f \n", totalWT / n);
}

int main()
{
    int n, at[MAX], bt[MAX];

    printf("FCFS Scheduling Algorithm\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &at[i]);
    
    printf("Enter burst times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &bt[i]);
    
    fcfs(n, at, bt);
    return 0;
}
