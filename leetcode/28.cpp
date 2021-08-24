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
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
        {
            return 0;
        }
        for (int i = 0; i < haystack.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < needle.size(); j++)
            {
                if (i + j >= haystack.size() || haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return i;
            }
        }
        return -1;
        // if (needle.size() == 0)
        // {
        //     return 0;
        // }

        // if (haystack.size() == 0)
        // {
        //     return -1;
        // }

        // int output = -1;
        // bool flag = true;
        // for (int i = 0; i < haystack.size(); i++)
        // {
        //     flag = true;
        //     for (int j = 0; j < needle.size(); j++)
        //     {
        //         if (haystack.size()-1 < i+j)
        //         {
        //             flag = false;
        //             break;
        //         }
        //         if (haystack[i + j] != needle[j])
        //         {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if (flag == true)
        //     {
        //         output = i;
        //         break;
        //     }
        // }

        // if (flag)
        // {
        //     return output;
        // }
        // else
        // {
        //     return -1;
        // }
    }
};
int main()
{
    Solution s;
    cout << s.strStr("", "ll") << endl;
}



class Solution {
public:
    int strStr(string haystack, string needle) {
        // kmp算法
        auto & s = haystack;
        auto & p  =needle;
        if(p.empty())return 0;
        vector<int> next(p.size(), -1);
        for (int i = 1; i < p.size(); i++) {
            int k = i - 1;
            while (k != -1 && p[next[k] + 1] != p[i])k = next[k];
            int nxtk = k == -1 ? -1 : next[k];
            if (p[nxtk + 1] == p[i])next[i] = nxtk + 1;
        }
        int now = -1;
        for (int i = 0; i < s.length(); i++) {
            while (now != -1 && s[i] != p[now + 1])now = next[now];
            if (p[now + 1] == s[i])now++;
            else now = -1;
            if (now == p.size() - 1)return i - p.size()+1;
        }
        return -1;
    }
};