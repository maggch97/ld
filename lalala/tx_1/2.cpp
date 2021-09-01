// https://www.nowcoder.com/test/question/11ee0516a988421abf40b315a2b28d08?pid=30545524&tid=47169735
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    string x;
    cin >> x;
    vector<string> v;
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i + j <= x.size())
            {
                v.push_back(x.substr(i, j));
            }
        }
    }
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());
    int k;
    cin >> k;
    cout << v[k - 1];
    return 0;
}