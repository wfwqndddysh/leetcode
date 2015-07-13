#include<iostream>
#include<cassert>

struct TreeNode
{
    int  val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        assert(p && q);

        if(!root || p->val==root->val || q->val==root->val)
            return root;

        if(q->val<p->val)
            std::swap(p, q);

        if(p->val<root->val && q->val>root->val)
            return root;
        else if(p->val>root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return lowestCommonAncestor(root->left, p, q);

        return nullptr;
    }
};

int main()
{
    Solution s;

    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(4);
    TreeNode d(2);

    a.left=&b;
    a.right=&c;

    b.right=&d;

    std::cout<<s.lowestCommonAncestor(&a, &d, &c)->val<<std::endl;
    return 0;
}

