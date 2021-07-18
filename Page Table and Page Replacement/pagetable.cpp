/* 
    Page Table
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Page 
{
    int pageNumber;
    int frame;
} Page;

int main()
{
    int logicalSize, physicalSize, pageSize;

    cout << "Enter the size of logical address space: ";
    cin >> logicalSize;
    cout << "Enter the size of physical address space: ";
    cin >> physicalSize;
    cout << "Enter the size of page: ";
    cin >> pageSize;

    int numberFrames = physicalSize / pageSize;
    int numberPages = logicalSize / pageSize;

    vector<Page> pageTable(numberPages);

    for(int i = 0; i < numberPages; i++)
        pageTable[i].frame = -1;

    cout << "Enter page table: \n";
    
    for(int i = 0; i < numberPages; i++)
    {
        int frame;
        bool flag = true;

        pageTable[i].pageNumber = i;
        
        cout << "Enter frame for page number " << i << ": ";
        cin >> frame;

        for(int j = 0; j < numberPages; j++)
        {
            if(frame != -1 && pageTable[j].frame == frame)
            {
                flag = false;
                cout << "Frame number already stored.\n";
            }
        }

        if(frame > numberFrames)
        {
            flag = false;
            cout << "Cannot exceed frame size.\n";
        }

        if(flag)
            pageTable[i].frame = frame;

    }

    int logicalAddress;
    
    cout << "Enter -1 to exit\n";

    while(1)
    {
        cout << "Enter logical address: ";
        cin >> logicalAddress;

        if(logicalAddress == -1)
            break;
        
        int pageNumber = logicalAddress / pageSize;
        int offset = logicalAddress % pageSize;

        if(pageTable[pageNumber].frame == -1)
            cout << "No such logical address exist.\n";
        else 
        {
            cout << "Page no.: " << pageNumber << "\n";
            cout << "Offset: " << offset << "\n";
            cout << "Frame no.: " << pageTable[pageNumber].frame << "\n";
            cout << "Physical Address: " << pageTable[pageNumber].frame * pageSize + offset << "\n";
        }
    }

}