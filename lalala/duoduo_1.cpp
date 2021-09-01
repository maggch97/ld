// https://www.nowcoder.com/test/question/3d6b53e097ea41bda049d111f30db28e?pid=30579184&tid=47166791
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
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long res = 1e18;
    do
    {
        long long x = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            x = x * 10 + nums[i];
            if (sum == n)
            {
                if (x == 0 || nums[0] != 0)
                {
                    res = min(res, x);
                }
            }
        }

    } while (next_permutation(nums.begin(), nums.end()));
    res = res == 1e18 ? -1 : res;
    cout << res;
    return 0;
}