#include <iostream>

using namespace std;

int main()
{

    int n, m, i, j, k;
    n = 5;
    m = 3;
    int alloc[5][3] = {{0, 1, 0},  
                       {2, 0, 0},  
                       {3, 0, 2},  
                       {2, 1, 1},  
                       {0, 0, 2}}; 
    // int alloc[5][3] = {{0, 0, 1},  
    //                    {3, 2, 0},  
    //                    {2, 1, 1},  
    //                    {0, 0, 0},  
    //                    {0, 0, 0}}; 

    int max[5][3] = {{7, 5, 3},  
                     {3, 2, 2},  
                     {9, 0, 2},  
                     {2, 2, 2},  
                     {4, 3, 3}}; 

    // int max[5][3] = {{8, 4, 3},  
    //                  {6, 2, 0},  
    //                  {3, 3, 3},  
    //                  {0, 0, 0},  
    //                  {0, 0, 0}};

    int avail[3] = {3, 3, 2};
    // int avail[3] = {3, 2, 0};

    int f[n];
    int ans[n], ind = 0;

    for (int i = 0; i < n; i++)
    {
        f[i] = 0;
    }
    int need[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    bool unsafe = false;
    bool finish = false;
    while (1)
    {
        int count = 0;
        unsafe = true;
        for (int i = 0; i < n; i++)
        {
            if (!f[i])
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (avail[j] < need[i][j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    unsafe = false;
                    f[i] = 1;
                    ans[ind++] = i;
                    for (int j = 0; j < m; j++)
                    {
                        avail[j] = avail[j] + alloc[i][j];
                    }
                }
            }

            if (ind == n)
            {
                finish = true;
            }
        }
        if (unsafe)
        {
            cout << "unsafe" << endl;
            break;
        }
        if (finish)
        {
            break;
        }
    }

    if (!unsafe)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "P" << ans[i] << "-->";
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < ind; i++)
        {
            cout << "P" << ans[i] << "-->";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                cout << "p" << i << endl;
            }
        }
    }
}