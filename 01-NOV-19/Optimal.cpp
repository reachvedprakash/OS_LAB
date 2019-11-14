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

    IOS;
    int n;
    cin >> n;
    int frame;
    cin >> frame;
    bool visited[N] = {0};
    vector<int> p;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (p.size() < frame)
        {
            p.push_back(arr[i]);
            sum++;
            visited[arr[i]] = true;
        }
        else if (visited[arr[i]])
        {
            continue;
        }
        else
        {
            sum++;
            int index;
            int max = INT_MIN;
            for (int j = 0; j < frame; j++)
            {
                int val = p[j];
                // cout << val << endl;
                int k = i;
                while (k <= n)
                {

                    if (arr[k] == val and max < k - i)
                    {
                        index = j;
                        max = k - i;
                        // cout << max << " " << index << endl;
                        break;
                    }
                    if (arr[k] == val)
                    {
                        break;
                    }
                    if (k == n - 1)
                    {
                        index = j;
                        max = n - i;
                        // cout << "last " << max << " " << index << endl;
                    }
                    k++;
                }
            }
            visited[p[index]] = false;
            p[index] = arr[i];
            visited[arr[i]] = true;
        }
    }
    cout << sum << endl;
    return 0;
}