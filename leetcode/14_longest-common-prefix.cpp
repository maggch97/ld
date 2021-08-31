#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string> strs) {
        if (strs.size()==0)
        {
            return "";
        }
        // aa
        // a
        for(int i=0;i<strs[0].size();i++)
        {
            for(int j=0;j<strs.size();j++)
            {
                // aa, i = 100
                if(strs[j].size()<=i || strs[j][i]!=strs[0][i])
                {
                    // https://www.cnblogs.com/zhudingtop/p/11394564.html
                    // i = 0 substr(0,0) = ""
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
        //
    }
};

int main(){
    cout << Solution().longestCommonPrefix({"","",""});
    cout << Solution().longestCommonPrefix({});
    cout << Solution().longestCommonPrefix({"","a"});
    cout << Solution().longestCommonPrefix({"a",""});
    cout << Solution().longestCommonPrefix({"aaaaa","a"});
}