
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, INT_MAX));
        dp [0][1] = nums[0];
        for (int i=1; i<n; i++)
        {
            for (int j=1; j<=i+1; j++)
            {
                if (j==1 || nums[i] > dp[i-1][j-1])
                {
                    dp [i][j] = min (dp[i-1][j], nums[i]);
                }
                else
                {
                    dp [i][j] = dp [i-1][j];
                }
            }
        }
        int count =n;
        while (dp[n-1][count] == INT_MAX)
        {
            count --;
        }
        return count;
    }
};
int main(){
    cout << "res: " << Solution().lengthOfLIS({10,9,2,5,3,7,101,18});
}