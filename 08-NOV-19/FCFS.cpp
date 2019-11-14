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
    int sum = 0;
    for (int i = 0; i < n ; i++)
    {

        int tmp;
        cin >> tmp;
        sum += abs( tmp - head );
        head = tmp;
    }

    cout << sum << endl;
    return 0;
}