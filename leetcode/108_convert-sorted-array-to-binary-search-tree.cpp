
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *dfs(const vector<int> &nums, int L, int R) // 返回 nums[L 到 R] 生成的子树的根节点
    {
        if (L>R)
        {
            return nullptr;
        }
        int mid = (L+R)/2;
        TreeNode *root = new TreeNode(nums[mid]);

        root -> left = dfs (nums, L, mid-1);
        root -> right = dfs (nums,  mid+1, R);
        return root;

    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return dfs(nums, 0, nums.size() - 1);

        TreeNode *root = new TreeNode();
        TreeNode *current = root;
        int length = nums.size();
    

        int middle = length / 2;

        if (length == 0)
            return root;
        else if (length > 0)
        {
            root->val = nums[middle];
            int i = middle, j = middle;
            while (i > 0)
            {
                TreeNode *LN = new TreeNode();
                current->left = LN;
                LN->val = nums[--i];
                current = current->left;
            }
            current = root;
            while (j < length - 1)
            {
                TreeNode *RN = new TreeNode();
                current->right = RN;
                RN->val = nums[++j];
                current = current->right;
            }
        }
        return root;
    }
};