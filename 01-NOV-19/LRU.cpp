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
int arr[N] = {0};
int main()
{
    int val = 0, sum = 0;
    set<pii> s;
    int n;
    cin >> n;
    int frame;
    cin >> frame;
    while (val > -1 * n)
    {
        val--;
        int tmp;
        cin >> tmp;
        if (!arr[tmp] and s.size() < frame)
        {
            sum++;
            s.insert(mp(val, tmp));
            arr[tmp] = val;
        }
        else if (arr[tmp])
        {
            auto f = s.find(mp(arr[tmp], tmp));
            s.erase(f);
            s.insert(mp(val, tmp));
            arr[tmp] = val;
        }
        else
        {
            sum++;
            auto p = *(prev(s.end()));
            s.erase(prev(s.end()));
            arr[p.second] = 0;
            arr[tmp] = val;
            s.insert(mp(val, tmp));
        }
    }
    cout << sum << endl;
    return 0;
}