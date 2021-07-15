/* 
    Optimal Page Replacement Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

bool search(int key, vector<int> &frame)
{
    for (int i = 0; i < frame.size(); i++)
        if (frame[i] == key)
            return true;
    return false;
}

int predict(int pages[], vector<int> &frame, int pageCount, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i < frame.size(); i++)
    {
        int j;
        for (j = index; j < pageCount; j++) 
        {
            if (frame[i] == pages[j]) 
            {
                if (j > farthest) 
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        if (j == pageCount)
            return i;
    }

    if(res == -1)
        return 0;
    else 
        return res;
}

int pageFaults(int pages[], int pageCount, int frameCount)
{
    vector<int> frame;

    int hit = 0;
    for (int i = 0; i < pageCount; i++) 
    {
        if (search(pages[i], frame)) 
        {
            hit++;
            continue;
        }

        if (frame.size() < frameCount)
            frame.push_back(pages[i]);

        else 
        {
            int j = predict(pages, frame, pageCount, i + 1);
            frame[j] = pages[i];
        }
    }
    
    return pageCount - hit;
}

int main()
{
    int frameCount;
    cout << "Enter number of frames: ";
    cin >> frameCount;

    int pageCount;
    cout << "Enter number of pages: ";
    cin >> pageCount;

    int pages[pageCount];

    cout << "Enter the pages: ";
    for(int i = 0; i < pageCount; i++)
        cin >> pages[i];

    int faults = pageFaults(pages, pageCount, frameCount);

    cout << "The number of page faults: " << faults << endl;

    return 0;
}