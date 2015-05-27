#include<iostream>
#include<cassert>
#include<vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> output;
        rec(root, output);
        return output;
    }

    void rec(TreeNode* root, std::vector<int>& output)
    {
        if(!root)
            return;

        rec(root->left, output);
        rec(root->right, output);
        output.push_back(root->val);
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

