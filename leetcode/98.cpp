
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
    pair<int, int> dfs(bool &valid, TreeNode *current) // 返回以 current 为根的子树中的最大和最小值
    {
        if (current == nullptr)
        {
            // 只有 root 是 nullptr 才会走进这个逻辑，所以随便返回个值也没有问题
            return {0, 0};
        }
        //   min, max
        pair<int, int> ret = {current->val, current->val};
        
        if (current->left == nullptr)
        {
            pair<int, int> leftRet = dfs(valid, current->left);
            ret.first = min(ret.first, leftRet.first);
            ret.second = max(ret.second, leftRet.second);
            if (current->val <= leftRet.second)
            {
                valid = false;
            }
        }
        if (current->right == nullptr)
        {
            pair<int, int> rightRet = dfs(valid, current->right);
            ret.first = min(ret.first, rightRet.first);
            ret.second = max(ret.second, rightRet.second);
            if (current->val >= rightRet.first)
            {
                valid = false;
            }
        }

        return ret;
    }
    bool isValidBST(TreeNode *root)
    {
        bool valid = true;
        dfs(valid, root);
        return valid;
    }
};