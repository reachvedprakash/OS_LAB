#include <iostream>
#include <bits/stdc++.h>
#include <utility>
#include <queue>

using namespace std;

class PAIR
{
public:
    int pid;
    int arrival;
    int exec;
    int rem;
};

struct CompareExec
{
    bool operator()(PAIR p1, PAIR p2)
    {
        return p1.rem > p2.rem;
    }
};

int main()
{
    long long N;
    cin >> N;
    PAIR pro[N];
    for (int i = 0; i < N; i++)
    {
        cin >> pro[i].pid >> pro[i].arrival >> pro[i].exec;
        pro[i].rem = pro[i].exec;
    }
    int E;
    priority_queue<PAIR, vector<PAIR>, CompareExec> execuSpace;
    int EndingTym[N];
    for (int i = 0; i < N; i++)
    {
        EndingTym[i] = 0;
    }
    int time = 0;
    int count = 0;
    for (int i = 0; i < N; time++)
    {

        while (pro[i].arrival <= time and i < N)
        {
            cout << "Done" << endl;
            execuSpace.push(pro[i]);
            i++;
        }

        PAIR temp = execuSpace.top();
        // cout << "Index : " << i << "time :" << time << " " << temp.pid << " " << temp.rem << endl;
        temp.rem = temp.rem - 1;
        if (temp.rem == 0)
        {
            EndingTym[temp.pid] = time + 1 ;
            count++;
            execuSpace.pop();
        }
        else
        {
            execuSpace.pop();
            execuSpace.push(temp);
        }

        if (count == N)
        {
            break;
        }
    }
    // time--;
    while( !execuSpace.empty() )
    {
        PAIR temp = execuSpace.top();
        cout << temp.pid << " " << temp.rem << " " << time << endl;
        time = time + temp.rem;
        EndingTym[temp.pid] = time  ;
        execuSpace.pop();
    }

    for (int i = 0; i < N; i++)
    {
        cout << pro[i].pid << " " << EndingTym[i] - pro[i].arrival - pro[i].exec <<  endl;
    }
}