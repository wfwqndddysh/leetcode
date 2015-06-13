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
    bool hasPathSum(TreeNode* root, int sum)
    {
        sum_ = sum;
        if(!root) return false;
        return rec(root, 0);
    }
private:
    bool rec(TreeNode* root, int sum)
    {
        if(!root->left && root->right)
        {
            return sum+root->val==sum_;
        }
        else if(!root->right)
        {
            return rec(root->left, sum);
        }
        else if(!root->left)
        {
            return rec(root->right, sum);
        }
        else
        {
            return rec(root->left, sum+root->val) || rec(root->right, sum+root->val);
        }
    }
    
private:
    int sum_;
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

