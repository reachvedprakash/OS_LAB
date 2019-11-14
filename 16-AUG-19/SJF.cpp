#include <iostream>
#include <bits/stdc++.h>
#include <utility> 

class PAIR {
    public:
    int first;
    int second;
};
struct CompareExec { 
    bool operator()(PAIR p1, PAIR p2) 
    { 
        return p1.second > p2.second; 
    } 
}; 
using namespace std;
int main()
{
    long long N;
    cin >> N;
    PAIR pro[N];
    vector<vector<long long> > res(4);
    for( int i =0 ; i< N ; i++ )
    {
        cin >> pro[i].first >> pro[i].second;
    }

    priority_queue <PAIR , vector < PAIR >  , CompareExec  > execuSpace;

    long long arrival = pro[0].first;
    res[0].push_back(pro[0].first);
    res[1].push_back(pro[0].second);
    res[2].push_back(pro[0].first);
    res[3].push_back(pro[0].first);
    int j = 0 ;
    for( int i = 1 ; i < N ; )
    {
        execuSpace.push(pro[i]);
        i++;
        // cout << "First "<< execuSpace.top().first  << " Second " << execuSpace.top( ).second  << endl;
        // cout << pro[i].first << " check "  << res[2][j] << endl;
        while( pro[i].first < res[2][j] && i < N  )
        {
            execuSpace.push(pro[i]);
            // cout << " Line : First "<< pro[i].first  << " Second " << pro[i].second  << endl;
            i++;
        }
        res[0].push_back(execuSpace.top().first );
        res[1].push_back(execuSpace.top().second );
        res[2].push_back( res[2][j] + res[1][j]);
        res[3].push_back( res[2][j+1] - execuSpace.top().first );
        j++;
        execuSpace.pop();
        // cout << "First "<< execuSpace.top().first  << " Second " << execuSpace.top( ).second  << endl;
    }

    while( !execuSpace.empty()  )
    {
        res[0].push_back(execuSpace.top().first );
        res[1].push_back(execuSpace.top().second );
        res[2].push_back( res[2][j] + res[1][j]);
        res[3].push_back( res[2][j+1] - execuSpace.top().first );
        j++;
        execuSpace.pop();
        //  cout << "First "<< execuSpace.top().first  << " Second " << execuSpace.top( ).second  << endl;
    }


    cout << "Arrival " << "Execution " << "Service " << " "<< endl;
    for( int i = 0 ; i < N ; i++ )
    {
        cout << res[0][i] << "        " << res[1][i] << "       " << res[2][i] << "        " << res[3][i] << endl; 
    }

}