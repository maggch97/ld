#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector <int> dp(nums.size());
        if (nums.size() == 0) return 0;
        dp[0] = nums[0];
        int maxval=dp[0];
        for (int i=1; i<nums.size(); i++)
        {
            if(dp[i-1]<=0)
            {
                dp[i]=nums[i];
            }
            else
            {
                dp[i]=dp[i-1]+nums[i];
            }
            maxval = max(maxval,dp[i]);
        }
        return maxval;
    }
};
// int
// 2.1 * 10^9
// -2.1 *10^9

// long long
// 4 * 10^18
// -4 * 10^18

int main(){
    cout << INT_MAX;
}