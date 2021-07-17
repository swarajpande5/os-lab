/* 
    First Come First Serve Disk Scheduling
*/

#include <bits/stdc++.h>
using namespace std;

int fcfs(vector<int> request, int currentHead)
{
    int totalSeekLength = 0;
    
    cout << currentHead << "-> ";

    for(int i = 0; i < request.size(); i++)
    {
        if(i == request.size()-1)
            cout << request[i] << "\n";
        else 
            cout << request[i] << "-> ";

        totalSeekLength += abs(request[i] - currentHead);
        currentHead = request[i];
    }
    
    return totalSeekLength;
}

int main()
{
    int requestCount, currentHead;

    cout << "Enter number of requests: ";
    cin >> requestCount;

    vector<int> request(requestCount);

    cout << "Enter the requests: ";
    for(int i = 0; i < requestCount; i++)
        cin >> request[i];
    
    cout << "Enter initial position of R/W head: ";
    cin >> currentHead;

    int totalSeekLength = fcfs(request, currentHead);
    cout << "Total Seek Length is: " << totalSeekLength << "\n";

    return 0;
}