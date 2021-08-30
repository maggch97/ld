
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
    int countTree(TreeNode *root) // ROOT 为根的子树高度
    {
        if (root == nullptr)
        {
            return 0;
        }
        return max(countTree(root->left), countTree(root->right)) + 1;
    }
    void calNodeDepth(int depth, TreeNode *root, int &count)
    {
        // depth 是 root 节点的深度
        if (root == nullptr)
        {
            return;
        }
        cout << root->val << " depth is " << depth << endl;
        count = max(count, depth);
        calNodeDepth(depth + 1, root->left, count);
        calNodeDepth(depth + 1, root->right, count);
    }
    int maxDepth(TreeNode *root)
    {
        // 方法 2
        int count = 0;
        calNodeDepth(1, root, count);

        // 方法 1
        countTree(root);
    }
};