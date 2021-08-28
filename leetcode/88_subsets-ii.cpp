
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// [0,0,0,1,2,3]
// [1,2,0,3]

// [0, 0, 0, 1, 2, 3]  end
//  1
// [2, 5, 6]
//  2

// [0, 0 , 0 , 2, 3, 4]
// [1, 1, 1]
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < m; i++)
        {
            swap(nums1[nums1.size() - i - 1], nums1[m - i - 1]);
        }

        int p1 = nums1.size() - m;
        int p2 = 0;
        int size = 0;
        while (p1 != nums1.size() || p2 != nums2.size())
        {
            if (p1 == nums1.size())
            {
                nums1[size++] = nums2[p2++];
            }
            else if (p2 == nums2.size())
            {
                // swap(nums1[size++], nums1[p1++]);
            }
            else if (nums1[p1] < nums2[p2])
            {
                swap(nums1[size++], nums1[p1++]);
            }
            else
            {
                nums1[size++] = nums2[p2++];
            }
        }
    }
};