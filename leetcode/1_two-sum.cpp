#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // nums，[0, 8, 9]
        // nums2Idx, [{0,0},{8,1},{9,2}]
        vector<pair<int, int>> nums2Idx; // 第一位 value， 第二位 下标
        for (int i = 0; i < nums.size(); i++)
        {
            nums2Idx.push_back({nums[i], i});
        }
        sort(nums2Idx.begin(), nums2Idx.end());

        int j = nums2Idx.size() - 1;
        for (int i = 0; i < nums2Idx.size(); i++)
        {
            int x = target - nums2Idx[i].first;
            // 在 [i+1,size) 找到 x
            while (j > i && nums2Idx[j].first > x)
            {
                j--;
            }
            if (j > i && nums2Idx[j].first == x)
            {
                return {nums2Idx[i].second, nums2Idx[j].second};
            }

            /*
            int L = i+1, R=nums2Idx.size();
            while(L!=R){
                int mid = (L+R)/2;
                if(nums2Idx[mid].first>=x){
                    R=mid;
                }else{
                    L=mid+1;
                }
            }
            if(L!=nums2Idx.size() && nums2Idx[L].first==x){
                return {nums2Idx[i].second,nums2Idx[L].second};
            }
            */
        }
        return {};
    }
};

target = 11
1 2 3 4 5 6 7 8 9 10
nums 有序
如果 nums[i] +nums[j] > target
那么 与 nums[i + 1] 能够和为 target 的数下标一定小于等于 j, 
i 0 j 9 i 1 j 8 i 2 j 7