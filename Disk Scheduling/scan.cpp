/* 
    SCAN Disk Scheduling 
*/

#include <bits/stdc++.h>
using namespace std;

int scan(vector<int> request, int head, int diskSize, string direction)
{
    int totalSeekLength = 0;
    int distance, currTrack;
    int initialHead = head;

    vector<int> left, right;
    vector<int> sequence;

    if(direction == "left")
        left.push_back(0);
    else if(direction == "right")
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

    for(int run = 0; run < 2; run++)
    {
        if(direction == "left")
        {
            for(int i = left.size() - 1; i >= 0; i--)
            {
                currTrack = left[i];
                sequence.push_back(currTrack);
                totalSeekLength += abs(currTrack - head);
                head = currTrack;
            }
            direction = "right";
        }

        else if(direction == "right")
        {
            for(int i = 0; i < right.size(); i++)
            {
                currTrack = right[i];
                sequence.push_back(currTrack);
                totalSeekLength += abs(currTrack - head);
                head = currTrack;
            }
            direction = "left";
        }
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

    string direction;

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

    cout << "Enter the direction (left/right): ";
    cin >> direction;

    int totalSeekLength = scan(request, currentHead, diskSize, direction);
    cout << "Total Seek Length is: " << totalSeekLength << "\n";

    return 0;
}