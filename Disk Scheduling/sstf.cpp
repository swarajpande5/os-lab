/* 
    Shortest Seek Time First Disk Scheduling
*/

#include <bits/stdc++.h>
using namespace std;

int sstf(vector<int> request, int currentHead)
{
    int totalSeekLength = 0;
    int n = request.size();

    vector<int> visited(request.size(), false);

    cout << currentHead;
    
    while(n)
    {
        int min = 1e9;
        int minTrack, position;
        for(int i = 0; i < request.size(); i++)
        {
            if(abs(currentHead - request[i]) < min && !visited[i])
            {
                min = abs(currentHead - request[i]);
                minTrack = request[i];
                position = i;
            }
        }
        
        currentHead = request[position];
        visited[position] = true;
        totalSeekLength += min;

        cout << " -> " << request[position];
        n--;
    }
    
    cout << "\n";

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

    int totalSeekLength = sstf(request, currentHead);
    cout << "Total Seek Length is: " << totalSeekLength << "\n";

    return 0;
}