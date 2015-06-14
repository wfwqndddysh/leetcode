#include<iostream>
#include<cassert>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        return rec(root, 0);
    }
private:
    int rec(TreeNode* root, int depth)
    {
        if(!root) return depth;
        return std::max(rec(root->left, depth+1), rec(root->right, depth+1));
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

