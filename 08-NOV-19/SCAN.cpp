#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define sz(x) (int)x.size()
#define hell 1000000007
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < b; i++)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

const int N = 1e5 + 5;

int main()
{
    IOS;
    int n;
    cin >> n;
    int head;
    cin >> head;
    int FixHead = head;
    int sum = 0;
    set<int> s;
    s.insert(head);
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
        if (tmp < min)
        {
            min = tmp;
        }
        if (tmp > max)
        {
            max = tmp;
        }
    }

    cout << "Left : " << head + max << endl;
    cout << "Right : " << abs(200 - head) + abs(200 - min) << endl;


    int count = 0;
    auto p = s.find(head);
    auto q = p;
    auto r = p;
    cout << "Left " << endl;
    while (p != s.begin())
    {
        p--;
        int tmp = *p;
        cout << head << "-->" << tmp << " :: " << abs(head - tmp) << endl;
        count += abs(head - tmp);
        head = *p;
    }

    cout << head << "-->" << "0" << " :: " << abs(head - 0) << endl;
    count += abs(head - 0);
    head = 0;
    while (q != prev(s.end()))
    {

        q++;
        int tmp = *q;
        cout << head << "-->" << tmp << " :: " << abs(head - tmp) << endl;
        count += abs(head - tmp);
        head = *q;
    }

    cout << endl
         << "Left Count  : " << count << endl;



    head = FixHead;
    count = 0;
    p = s.find(head);
    q = p;
    r = p;
    cout << endl
         << "Right " << endl;
    while (q != prev(s.end()))
    {

        q++;
        int tmp = *q;
        cout << head << "-->" << tmp << " :: " << abs(head - tmp) << endl;
        count += abs(head - tmp);
        head = *q;
    }
    cout << head << "-->" << 200 << " :: " << abs(head - 200) << endl;
    count += abs(head - 200);
    head = 200;
    while (p != s.begin())
    {
        p--;
        int tmp = *p;
        cout << head << "-->" << tmp << " :: " << abs(head - tmp) << endl;
        count += abs(head - tmp);
        head = *p;
    }
    cout << endl
         << "Right Count  : " << count << endl;

    return 0;
}