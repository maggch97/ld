// https://www.nowcoder.com/test/question/11ee0516a988421abf40b315a2b28d08?pid=30545524&tid=47169735
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;
vector<int> s(1e7 + 1);
int find(int i)
{
    if (s[i] == i)
    {
        return i;
    }
    return s[i] = find(s[i]);
}

void merge(int i, int j)
{
    int fa = find(j);
    s[find(i)] = fa;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= 1e7; i++)
        {
            s[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            merge(x, y);
        }
        map<int, int> count;
        int res = 0;
        for (int i = 1; i <= 1e7; i++)
        {
            if (i != find(i))
            {
                res = max(res, ++count[find(i)]);
            }
        }
        cout << res + 1 << endl;
    }
}