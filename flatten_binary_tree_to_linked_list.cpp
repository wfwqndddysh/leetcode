#include<iostream>
#include<cassert>
#include<stack>

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
    void flatten(TreeNode* root)
    {
        if(!root) return;

        flatten(root->left);
        flatten(root->right);

        if(root->left)
        {
            auto right = root->right;
            root->right=root->left;

            root->left=nullptr;
            auto l = root->right;
            while(l->right)
            {
                l=l->right;
            }
            l->right = right;
        }
    }
};

class SolutionItr
{
public:
    void flatten(TreeNode* root)
    {
        while(root)
        {
            if(root->right && root->left)
            {
                auto l = root->left;
                for(; l->right; l=l->right);
                l->right=root->right;
            }
            if(root->left)
            {
                root->right=root->left;
                root->left=nullptr;
            }
            root=root->right;
        }
    }
};

int main()
{
    SolutionItr s;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);

    a.left=&b;
    a.right=&c;

    b.left=&d;
    b.right=&e;

    c.right=&f;

    s.flatten(&a);

    for(auto r=&a; r; r=r->right)
        std::cout<<r->val<<std::endl;

    return 0;
}

