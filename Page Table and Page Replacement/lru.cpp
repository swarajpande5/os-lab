/* 
    Least Recently Used Page Replacement Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

int pageFaults(vector<int> pages, int frameCount)
{
    unordered_set<int> set;
    vector<int> frame;

    int faults = 0;

    for(int i = 0; i < pages.size(); i++)
    {
        if(set.find(pages[i]) == set.end())
        {
            if(frame.size() == frameCount)
            {
                set.erase(frame[0]);
                frame.erase(frame.begin() + 0);

                set.insert(pages[i]);
                frame.push_back(pages[i]);
            }
            else 
            {
                set.insert(pages[i]);
                frame.push_back(pages[i]);
            }

            faults++;
        }
        else 
        {
            auto it = find(frame.begin(), frame.end(), pages[i]);
            frame.erase(it);
            frame.push_back(pages[i]);
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