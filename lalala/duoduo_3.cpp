// https://www.nowcoder.com/question/next?pid=30579184&qid=1712517&tid=47166791

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
    int n, m;
    cin >> n >> m;
    vector<int> A(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i + 1];
    }
    vector<int> preSum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        preSum[i] = (preSum[i - 1] + A[i]) % m;
    }
    map<int, int> count;
    count[0] = 1;
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += count[preSum[i]];
        count[preSum[i]]++;
    }
    cout << res;
}
