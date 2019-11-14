#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n, m, i, j, k, no;
    n = 5;
    m = 3;

    // cout << "Enter No. Of request" << endl;
    cin >> no;

    int req[no][m + 1];

    for (int i = 0; i < no; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            cin >> req[i][j];
        }
    }

    // for (int i = 0; i < no; i++)
    // {
    //     for (int j = 0; j < m + 1; j++)
    //     {
    //         cout << req[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int alloc[5][3] = {{0, 1, 0},
                       {2, 0, 0},
                       {3, 0, 2},
                       {2, 1, 1},
                       {0, 0, 2}};

    int max[5][3] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};

    int avail[3] = {3, 3, 2};
    bool error = false;
    for (int i = 0; i < no; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (req[i][j] > max[req[i][0]][j])
            {
                cout << "Error at request of Process " << req[i][0] << endl;
                error = true ;
                break;
            }
        }
        cout << endl;

    }

    if(error)
    {
        return 0;
    }

    int served[n];
    int ans[n], ind = 0;

    for (int i = 0; i < n; i++)
    {
        served[i] = 0;
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
            if (!served[i])
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
                    served[i] = 1;
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
            if (served[i] == 0)
            {
                cout << "p" << i << endl;
            }
        }
    }
}