/*
    First In First Out Page Replacement Algorithm 
*/

#include <bits/stdc++.h>
using namespace std;

int pageFaults(vector<int> pages, int frameCount)
{
    unordered_set<int> set;
    queue<int> frame;

    int faults = 0;

    for(int i = 0; i < pages.size(); i++)
    {
        if(set.size() < frameCount)
        {
            if(set.find(pages[i]) == set.end())
            {
                set.insert(pages[i]);
                frame.push(pages[i]);
                faults++;
            }
        }
        else 
        {
            if(set.find(pages[i]) == set.end())
            {
                int value = frame.front();
                frame.pop();
                set.erase(value);
                
                set.insert(pages[i]);
                frame.push(pages[i]);

                faults++;
            }
        }
    }

    return faults;
}

int main()
{
    int frameCount;
    cout << "Enter number of frames: ";
    cin >> frameCount;

    int pageCount;
    cout << "Enter number of pages: ";
    cin >> pageCount;

    vector<int> pages(pageCount);

    cout << "Enter the pages: ";
    for(int i = 0; i < pageCount; i++)
        cin >> pages[i];

    int faults = pageFaults(pages, frameCount);

    cout << "The number of page faults: " << faults << endl;

    return 0;
}

