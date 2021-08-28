#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    // [L,R] -> pos
    // [L,R) -> 
    int searchInsert(vector<int> nums, int target) {
        int L = 0;
        int R = nums.size();
        while (L != R)
        {
            int mid = (R+L)/2;
            if(target<=nums[mid])
            {
                R=mid;
            }
            else
            {
                L=mid+1;
            }
            cout << L << " " << R << " " << mid << endl;
        }
        // if (L >= nums.size()-1)
        // {
        //     if (target > nums[nums.size()-1])
        //     {
        //         return nums.size();
        //     }
        // }
        return L;
    }
};

int main()
{
    Solution s;

    cout<<s.searchInsert({1,3,5,6},3);
}