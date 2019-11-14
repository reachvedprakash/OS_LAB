#include <iostream>
#include <bits/stdc++.h>
#include <utility>
#include <queue>

class PAIR
{
public:
    int first;
    int second;
    int priority;
};
struct CompareExec
{
    bool operator()(PAIR p1, PAIR p2)
    {
        if (p1.priority != p2.priority)
        {
            return p1.priority < p2.priority;
        }
        return p1.second > p2.second;
    }
};
using namespace std;
int main()
{
    long long N;
    cin >> N;
    PAIR pro[N];
    vector<vector<long long> > res(5);
    for (int i = 0; i < N; i++)
    {
        cin >> pro[i].first >> pro[i].second >> pro[i].priority;
    }

    priority_queue<PAIR, vector<PAIR>, CompareExec> execuSpace;

    long long arrival = pro[0].first;
    execuSpace.push(pro[0]);
    // cout << "PUSH "
    //      << "First " << pro[0].first << " Second " << pro[0].second << " Priority " << pro[0].priority << endl;
    res[0].push_back(pro[0].first);
    res[1].push_back(pro[0].second);
    res[2].push_back(pro[0].first);
    res[3].push_back(pro[0].first);
    res[4].push_back(pro[0].priority);
    // cout << "***"
    //      << "First " << execuSpace.top().first << " Second " << execuSpace.top().second << " Priority " << execuSpace.top().priority << endl;
    execuSpace.pop();
    int j = 0;
    for (int i = 1; i < N;)
    {
        // cout << "PUSH "
        //      << "First " << pro[i].first << " Second " << pro[i].second << " Priority " << pro[i].priority << endl;
        execuSpace.push(pro[i]);
        i++;
        // cout << "***"  <<  "First "<< execuSpace.top().first  << " Second " << execuSpace.top( ).second   << " Priority " <<  execuSpace.top( ).priority << endl;
        // cout << pro[i].first << " check " << res[2][j] + res[1][j] << endl;
        while (pro[i].first < res[2][j] + res[1][j] && i < N)
        {
            // cout << "PUSH "
            //      << "First " << pro[i].first << " Second " << pro[i].second << " Priority " << pro[i].priority << endl;
            execuSpace.push(pro[i]);
            // cout << "***"  <<  "First "<< execuSpace.top().first  << " Second " << execuSpace.top( ).second   << " Priority " <<  execuSpace.top( ).priority << endl;
            // cout << " Line : First "<< pro[i].first  << " Second " << pro[i].second  << endl;
            i++;
        }
        res[0].push_back(execuSpace.top().first);
        res[1].push_back(execuSpace.top().second);
        res[2].push_back(res[2][j] + res[1][j]);
        res[3].push_back(res[2][j + 1] - execuSpace.top().first);
        res[4].push_back(execuSpace.top().priority);
        j++;
        // cout << "***"
        //      << "First " << execuSpace.top().first << " Second " << execuSpace.top().second << " Priority " << execuSpace.top().priority << endl;
        execuSpace.pop();
        // cout << "First "<< execuSpace.top().first  << " Second " << execuSpace.top( ).second  << " Priority " <<  execuSpace.top( ).priority <<  "###" << endl;
    }

    while (!execuSpace.empty())
    {
        res[0].push_back(execuSpace.top().first);
        res[1].push_back(execuSpace.top().second);
        res[2].push_back(res[2][j] + res[1][j]);
        res[3].push_back(res[2][j + 1] - execuSpace.top().first);
        res[4].push_back(execuSpace.top().priority);
        j++;
        //  cout << "***"
        //      << "First " << execuSpace.top().first << " Second " << execuSpace.top().second << " Priority " << execuSpace.top().priority << endl;
        execuSpace.pop();
        //  cout << "First "<< execuSpace.top().first  << " Second " << execuSpace.top( ).second << " Priority " <<  execuSpace.top( ).priority << endl;
    }

    cout << "Arrival "
         << "Execution "
         << "Priority "
         << "Service "
         << "Waiting " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << res[0][i] << "        " << res[1][i] << "           " << res[4][i]
             << "        " << res[2][i] << "        " << res[3][i] << endl;
    }
}