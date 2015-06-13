#include<iostream>
#include<cassert>
#include<vector>

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
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum)
    {
        sum_ = sum;
        rec(root, 0, {});
        return res_;
    }
private:
    void rec(TreeNode* root, int sum, std::vector<int> elems)
    {
        if(!root) return;

        if(!root->left && !root->right)
        {
            if(sum+root->val!=sum_)
                return;

            res_.push_back(elems);
            res_.back().push_back(root->val);
        }
        elems.push_back(root->val);
        rec(root->left, sum+root->val, elems);
        rec(root->right, sum+root->val, elems);
    }
    
private:
    int sum_;
    std::vector<std::vector<int>> res_;
};

int main()
{
    Solution s;
    TreeNode a(1);
    s.pathSum(&a, 1);
    std::cout<<std::endl;
    return 0;
}

