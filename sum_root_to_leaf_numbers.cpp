#include<iostream>
#include<cassert>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution
{
public:
    int sumNumbers(TreeNode* root)
    {
        sum_ = 0;
        rec(root, 0);
        return sum_;
    }
private:
    void rec(TreeNode* root, int sum)
    {
        if(!root) return;

        if(!root->left && !root->right)
        {
            sum = sum*10+root->val;
            sum_ += sum;
        }
        else
        {
            rec(root->right, sum*10+root->val);
            rec(root->left, sum*10+root->val);
        }
    }
private:
    int sum_;
};

int main()
{
    Solution s;

    TreeNode a(4);
    TreeNode b(9);
    TreeNode c(1);
    TreeNode d(0);
    a.left=&b;
    a.right=&c;
    b.left=&d;

    std::cout<<s.sumNumbers(&a)<<std::endl;
    return 0;
}

