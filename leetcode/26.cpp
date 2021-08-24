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
    int removeDuplicates(vector<int> &nums)
    {
        if(nums.size()==0)
        {
            return 0;
        }
        int size = 1;
        for (int i=1; i<nums.size();i++)
        {
            if (nums[i]!=nums[i-1])
            {
                nums[size++] = nums[i];
            }
        }
        return size;
    }
};
int main()
{
}