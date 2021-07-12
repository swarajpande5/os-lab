/*
    Shortest Remaining Time First Process Scheduling Algorithm
    (Preemptive)
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Process 
{
    int pid;
    int at, bt, ct, st, tat, wt, rt;
}Process;

void srtf(vector<Process> p, int n)
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
        int index  = -1;
        int min = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= currTime && !isCompleted[i])
            {
                if(burstRemaining[i] < min)
                {
                    min = burstRemaining[i];
                    index = i;
                }
            }

            if(burstRemaining[i] == min)
            {
                if(p[i].at < p[index].at)
                {
                    min = burstRemaining[i];
                    index = i;
                }
            }
        }

        if(index != -1)
        {
            if(burstRemaining[index] == p[index].bt)
                p[index].st = currTime;
            
            burstRemaining[index]--;
            currTime++;

            if(burstRemaining[index] == 0)
            {
                p[index].ct = currTime;
                p[index].tat = p[index].ct - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;
                p[index].rt = p[index].st - p[index].at;

                totalTAT += p[index].tat;
                totalWT += p[index].wt;
                totalRT += p[index].rt;

                isCompleted[index] = true;
                completed++;
            }
        }

        else 
            currTime++;
    }

    cout << "PID\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for(int i = 0; i < n; i++) {
        cout << p[i].pid << "\t";
        cout << p[i].at << "\t";
        cout << p[i].bt << "\t";
        cout << p[i].ct << "\t";
        cout << p[i].tat << "\t";
        cout << p[i].wt << "\t";
        cout << p[i].rt << "\n";
    }
    cout << "Average Turnaround Time = "<< totalTAT/n << endl;
    cout << "Average Waiting Time = "<< totalWT/n << endl;
    cout << "Average Response Time = " << totalRT/n << endl;

}

int main()
{
    int n;

    cout << "Shortest Remaining Time First\n";
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

    srtf(p, n);

    return 0;
}