/* 
    Round Robin Process Scheduling Algorithm 
    (Preemeptive) 
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Process 
{
    int pid;
    int at, bt, ct, tat, wt;
}Process;

bool testCompletion(vector<bool> finish, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(!finish[i])
            return false;
    }
    return true;
}

void roundRobin(vector<Process> p, int n, int tq)
{
    int currTime;
    vector<bool> finish(n, false);
    vector<int> burstRemaining(n);
    float totalTAT, totalWT;

    // Initializing burstRemaining
    for(int i = 0; i < n; i++)
        burstRemaining[i] = p[i].bt;
    
    currTime = 0;
    totalTAT = 0;
    totalWT = 0;

    int i = 0;
    while(testCompletion(finish, n) != true)
    {
        if(burstRemaining[i] >= tq)
        {
            currTime += tq;
            burstRemaining[i] -= tq;

            if(burstRemaining[i] == 0)
            {
                p[i].ct = currTime;
                finish[i] = true;
            }
        }

        else
        {
            if(!finish[i])
            {
                currTime += burstRemaining[i];
                p[i].ct = currTime;
                finish[i] = true;
            }
        }
        i = (i + 1) % n;
    }

    for(int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }

    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) 
    {
        cout << p[i].pid << "\t";
        cout << p[i].at << "\t";
        cout << p[i].bt << "\t";
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

    cout << "Round Robin Scheduling\n";
    cout<< "Enter number of processes: ";
    cin >> n;

    int tq;
    cout << "Enter time quantum: ";
    cin >> tq;

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

    roundRobin(p, n, tq);

    return 0;
}