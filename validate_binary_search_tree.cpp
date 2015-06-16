#include<iostream>
#include<cassert>
#include<climits>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//考虑到了整数溢出问题，不过第一次并没有解决好
//没有考虑到排除元素相等的情况
class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        return rec(root, (int64_t)INT_MIN-1, (int64_t)INT_MAX+1);
    }

private:
    bool rec(TreeNode* root, int64_t min_val, int64_t max_val)
    {
        if(!root) return true;

        bool l_be_bst = true;
        bool r_be_bst = true;

        if(root->val <= min_val || root->val >= max_val) return false;

        if(root->left)
            l_be_bst = rec(root->left, min_val, root->val);

        if(l_be_bst && root->right)
            r_be_bst = rec(root->right, root->val, max_val);

        return l_be_bst && r_be_bst;
    }
};

int main()
{
    Solution s;

    /*
    TreeNode a(10);
    TreeNode b(5);
    TreeNode c(15);
    TreeNode d(6);
    TreeNode e(20);

    a.left = &b;
    a.right = &c;

    c.left=&d;
    c.right=&e;
    */


    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(5);

    a.left=&b;
    a.right=&c;

    TreeNode d(0);
    TreeNode e(2);

    b.left=&d;
    b.right=&e;

    TreeNode f(4);
    TreeNode g(6);

    c.left=&f;
    c.right=&g;

    TreeNode h(3);
    e.right=&h;

    std::cout<<s.isValidBST(&a)<<std::endl;
    return 0;
}

