#include<iostream>
#include<cassert>
#include<cmath>

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
    int countNodes(TreeNode* root)
    {
        if(!root) return 0;

        auto l=root;
        auto r=root;

        int hl=0;
        while(l) { hl++; l=l->left; };

        int hr=0;
        while(r) { hr++; r=r->right; };

        if(hl==hr) return std::pow(2, hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

