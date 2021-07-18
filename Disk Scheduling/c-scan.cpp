/* 
    C-SCAN Disk Scheduling 
*/

#include <bits/stdc++.h>
using namespace std;

int cscan(vector<int> request, int head, int diskSize)
{
    int totalSeekLength = 0;
    int distance, currTrack;
    int initialHead = head;

    vector<int> left, right;
    vector<int> sequence;

    left.push_back(0);
    right.push_back(diskSize - 1);

    for(int ele: request)
    {
        if(ele < head)
            left.push_back(ele);
        if(ele > head)
            right.push_back(ele);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for(int i = 0; i < right.size(); i++)
    {
        currTrack = right[i];
        sequence.push_back(currTrack);
        totalSeekLength += abs(currTrack - head);
        head = currTrack;
    }

    head = 0;
    totalSeekLength += diskSize - 1;

    for(int i = 0; i < left.size(); i++)
    {
        currTrack = left[i];
        sequence.push_back(currTrack);
        totalSeekLength += abs(currTrack - head);
        head = currTrack;
    }

    cout << initialHead;
    for(int i = 0; i < sequence.size(); i++)
        cout << " -> " << sequence[i];
    cout << "\n";

    return totalSeekLength;
}

int main()
{
    int requestCount, currentHead, diskSize;

    cout << "Enter the disk size: ";
    cin >> diskSize;

    cout << "Enter number of requests: ";
    cin >> requestCount;

    vector<int> request(requestCount);

    cout << "Enter the requests: ";
    for(int i = 0; i < requestCount; i++)
        cin >> request[i];
    
    cout << "Enter initial position of R/W head: ";
    cin >> currentHead;

    int totalSeekLength = cscan(request, currentHead, diskSize);
    cout << "Total Seek Length is: " << totalSeekLength << "\n";

    return 0;
}