/*
    Banker's Algorithm for Deadlock Avoidance
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, r, safeCount = 0;
    cout << "\nEnter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> r; 
    cout << "\n";

    vector<bool> isCompleted(n, false);
    vector<int> available(r);
    vector<int> safeSeq(n);
    vector<vector<int>> allocation(n, vector<int>(r));
    vector<vector<int>> max(n, vector<int>(r));
    vector<vector<int>> need(n, vector<int>(r));

    cout << "Enter the resource allocation matrix for the processes: \n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cin >> allocation[i][j];
        }
    }
    cout << "\n";

    cout << "Enter the maximum resource matrix for the processes: \n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cin >> max[i][j];
        }
    }
    cout << "\n";

    cout << "Enter the available instances of each resource: \n";
    for(int i = 0; i < r; i++)
    {
        cin >> available[i];
    }
    cout << "\n";

    cout << "The need matrix is: \n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            cout << need[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // Evaluating and checking for Safe Sequence

    safeCount = 0;

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            if(isCompleted[i] == false)
            {
                bool needFlag = true;
                for(int j = 0; j < r; j++)
                {
                    if(need[i][j] > available[j])
                    {
                        needFlag = false;
                        break;
                    }
                }

                if(needFlag)
                {
                    safeCount++;
                    isCompleted[i] = true;
                    safeSeq[safeCount - 1] = i;

                    for(int j = 0; j < r; j++)
                    {
                        available[j] = available[j] + allocation[i][j];
                    }
                }
            }
        }
    }

    if(safeCount != n)
    {
        cout << "UNSAFE STATE ! \n";
    }

    if(safeCount == n)
    {
        cout << "SAFE STATE ! \n";
        cout << "The safe sequence is: ";
        for(int i = 0; i < n; i++)
        {
            cout << "P" << safeSeq[i]+1 << " ";
        }
        cout << "\n";

        cout << "The available resource matrix is: ";
        for(int i = 0; i < r; i++)
        {
            cout << available[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}