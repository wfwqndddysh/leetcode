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
    int kthSmallest(TreeNode* root, int k)
    {
        if(!root) return 0;
        return rec(root, k);
    }

private:
    int rec(TreeNode* root, int& k)
    {
        if(!root) return 0;
        int val=rec(root->left, k);
        if(k==0) return val;
        if(--k==0) return root->val;
        return rec(root->right, k);
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

