// https://www.nowcoder.com/test/question/3d6b53e097ea41bda049d111f30db28e?pid=30579184&tid=47166791

#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string x, y;
    cin >> x >> y;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += abs((int)x[i] - (int)y[i]);
    }
    cout << res;
}