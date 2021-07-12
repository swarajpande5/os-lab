/*
    Shortest Job First Process Scheduling Algorithm
    (Non-Preemptive)
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Process 
{
    int pid;
    int at, bt, ct, tat, wt, rt;
}Process;


void sjf(vector<Process> p, int n)
{
    int currTime, completed; 
    vector<bool> isCompleted(n, false);
    float totalTAT, totalWT, totalRT;

    currTime = 0; 
    completed = 0;
    totalTAT = 0;
    totalWT = 0;
    totalRT = 0;

    while(completed != n)
    {
        int index = -1;
        int min = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= currTime && !isCompleted[i])
            {
                if(p[i].bt < min)
                {
                    min = p[i].bt;
                    index = i;
                }

                if(p[i].bt == min)
                {
                    if(p[i].at < p[index].at)
                    {
                        min = p[i].bt;
                        index = i;
                    }
                }
            }
        }

        if(index != -1)
        {
            p[index].ct = currTime + p[index].bt;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = currTime - p[index].at;

            totalTAT += p[index].tat;
            totalWT += p[index].wt;
            totalRT += p[index].rt;

            isCompleted[index] = true;
            completed++;
            currTime = p[index].ct;
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

    cout << "Shortest Job First Algorithm\n";
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

    sjf(p, n);

    return 0;
}