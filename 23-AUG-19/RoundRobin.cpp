#include <iostream>
#include <bits/stdc++.h>
#include <utility>
#include <queue>
using namespace std;
int n = 1e4 + 4;
class PAIR
{
public:
    int first;
    int second;
    int rem;
};

int main()
{
    int N;
    cin >> N;
    PAIR pro[N];
    int EndingTym[N];
    for (int i = 0; i < N; i++)
    {
        EndingTym[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> pro[i].first >> pro[i].second;
        pro[i].rem = pro[i].second;
    }
    int frame = 3;
    int i = 0;
    int t = 0;
    int count = 0;
    while (1)
    {
        
        if (pro[i].first > t)
        {
            t = pro[i].first;
        }
        cout << "INDEX  : " << i << " Time  " << t << endl;

        if (count == N)
        {
            break;
        }

        if (!EndingTym[i])
        {
            if (pro[i].rem > frame)
            {
                pro[i].rem -= frame;
                t += frame;
            }
            else
            {
                t += pro[i].rem;
                pro[i].rem = 0;
                EndingTym[i] = t;
                count++;
                cout << t << "  " << count << endl;
            }

            if (i != N and pro[i + 1].first > t)
            {
                continue;
            }
            else
            {
                i = (i + 1) % N;
            }
        }
        else
        {
            cout << "Skip"
                 << " " << count << endl;
            i = (i + 1) % N;
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        cout << i << " " << EndingTym[i] - pro[i].first - pro[i].second << endl;
    }
}
