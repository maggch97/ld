#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int pre = 0;
        string output = "";
        string *longString;

        // 等价
        string *longString = (a.size() > b.size() ? &a : &b);

        for (int i = 0; i < max(a.size(), b.size()); i++)
        {
            // a = 123
            // b = 123456
            // 3 和 6 相同位
            int aPos = a.size() - i - 1;
            int bPos = b.size() - i - 1;
            int temp = 0;
            int temp2 = 0;
            if (aPos >= 0)
            {
                temp += a[aPos] - '0';
            }
            if (bPos >= 0)
            {
                temp += b[bPos] - '0';
            }
            temp2 = (temp + pre) / 2;
            temp = (temp + pre) % 2;
            (*longString)[(*longString).size() - i - 1] = '0' + temp;
            pre = temp2;
        }
        if (pre != 0)
        {
            (*longString) = '1' + (*longString);
        }
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= 20; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return (*longString);
    }
};