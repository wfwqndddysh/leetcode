#include<iostream>
#include<cassert>

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
    bool isBalanced(TreeNode* root)
    {
        int depth = 0;
        return rec(root, depth);
    }
private:
    bool rec(TreeNode* root, int& depth)
    {
        if(!root) return true;
        int left = 0;
        int right = 0;
        bool l = rec(root->left, left);
        bool r = rec(root->right, right);
        depth = std::max(left, right)+1;
        return l && r && std::abs(left-right)<=1;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

