/*
    Priority Process Scheduling Algorithm
    (Preemptive)
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Process 
{
    int pid;
    int at, bt, st, ct, tat, wt, rt;
    int priority;
}Process;

void priority(vector<Process> p, int n)
{
    int currTime, completed;
    vector<bool> isCompleted(n, false);
    vector<int> burstRemaining(n);
    float totalTAT, totalWT, totalRT;

    // Initializing burstRemaining
    for(int i = 0; i < n; i++)
        burstRemaining[i] = p[i].bt;
    
    currTime = 0;
    completed = 0;
    totalTAT = 0;
    totalWT = 0;
    totalRT = 0;

    while(completed != n)
    {
        int index = -1;
        int max = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= currTime && !isCompleted[i])
            {
                if(p[i].priority > max)
                {
                    max = p[i].priority;
                    index = i;
                }

                if(p[i].priority == max)
                {
                    if(p[i].at < p[index].at)
                    {
                        max = p[i].priority;
                        index = i;
                    }
                }
            }
        }

        if(index != -1)
        {
            burstRemaining[index] -= 1;
            currTime++;

            if(burstRemaining[index] == 0)
            {
                p[index].ct = currTime;
                p[index].tat = p[index].ct - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;

                totalTAT += p[index].tat;
                totalWT += p[index].wt;

                isCompleted[index] = true;
                completed++;
            }
        }
        else 
        {
            currTime++;
        }

    }

    cout << "PID\tAT\tBT\tPT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) 
    {
        cout << p[i].pid << "\t";
        cout << p[i].at << "\t";
        cout << p[i].bt << "\t";
        cout << p[i].priority << "\t";
        cout << p[i].ct << "\t";
        cout << p[i].tat << "\t";
        cout << p[i].wt << "\n";
    }
    cout << "Average Turnaround Time = "<< totalTAT/n << endl;
    cout << "Average Waiting Time = "<< totalWT/n << endl;
}

int main()
{
    int n;

    cout << "Priority Scheduling\n";
    cout<< "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    cout << "Enter Arrival times: ";
    for(int i = 0; i < n; i++)
    {
        p[i].pid = i+1;
        cin >> p[i].at;
    }

    cout << "Enter Burst times: ";
    for(int i = 0; i < n; i++)
        cin >> p[i].bt;

    cout << "Enter Priority: ";
    for(int i = 0; i < n; i++)
        cin >> p[i].priority;

    priority(p, n);

    return 0;
}