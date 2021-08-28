
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
    void dfs (vector <int> &output, TreeNode *current)
    {
        if(current == nullptr)
        {
            return;
        }
        output.push_back(current -> val);
        dfs (output, current -> left);
        dfs (output, current -> right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector <int> output;
        dfs (output, root);
        return output;
    }
};