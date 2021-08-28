#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    vector<int> b(n);
    int n;
    int dp[n][n];
    // dp[i][j] 表示到 i 为止，取出的长度为 j 的递增子序列的结尾 最小是多少
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=i+1;j++){ // j 是到 i 为止，长度为 j 的序列。可能不包含 i 这位
            if(b[i]>dp[i-1][j-1]){
                dp[i][j] = min(dp[i-1][j], b[i])
                // 两种情况
                // 1. b[i] 作为长度为 j 的递增子序列结尾并不是最优的，在 i-1 的时候就已经有最优的结尾了（并不一定是i-1，可能是小于等于i-1
                // 2. b[i] 作为长度为 j 的递增子序列结尾是最优的

            }else{
                dp[i][j] = dp[i-1][j];
                // 到 i-1 没法取出一个长度为 j-1，并且结尾小于 b[i] 的序列，所以我们取不出一个 b[i] 结尾的长度为 j 的递增序列
                // 这时候我们只能寄希望于在 i-1 的时候就已经取出了长度为 j 的递增子序列
                // 比如 5 6 1
                // 当我们看到最后一位的时候，是不存在以 1 结尾长度为 2的子序列的。但是我们在最后一位之前其实就找到了这样的序列 5，6
            }
            if(dp[i][j] 是一个合法的数字){
                // 这里的合法数字是说我们能够在到 i 为止，取出一个长度为 j 的序列
                // 如果不是合法数字说明我们没有办法取出这样的序列
                res = max(res,j);
            }
        }
    }
    return res;
}