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
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root) return nullptr;

        auto l=invertTree(root->left);
        auto r=invertTree(root->right);

        root->left=r;
        root->right=l;

        return root;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

