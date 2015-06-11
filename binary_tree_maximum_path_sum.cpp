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

class Solution
{
public:
    int maxPathSum(TreeNode* root)
    {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;

        int partition_max = 0;
        int max_val = rec(root, partition_max);
        return std::max(max_val, partition_max);
    }
private:
    int rec(TreeNode* root, int& partition_max)
    {
        if(!root) return partition_max;

        int left_partition_max = 0;
        int right_partition_max = 0;

        if(!root->left && !root->right)
        {
            partition_max = root->val;
            return partition_max;
        }
        else if(!root->right)
        {
            int left_max_val = rec(root->left, left_partition_max);
            partition_max = std::max(left_partition_max + root->val, root->val);
            return std::max(left_max_val, std::max(root->val, partition_max));
        }
        else if(!root->left)
        {
            int right_max_val = rec(root->right, right_partition_max);
            partition_max = std::max(right_partition_max + root->val, root->val);
            return std::max(right_max_val, std::max(root->val, partition_max));
        }
        else
        {
            int left_max = rec(root->left, left_partition_max);
            int right_max = rec(root->right, right_partition_max);

            int max_val = std::max(left_max
                    , std::max(right_max
                        , std::max(left_partition_max+right_partition_max+root->val
                            , root->val)));
            partition_max = std::max(root->val
                            , std::max(left_partition_max+root->val
                                , right_partition_max+root->val));

            return std::max(max_val, partition_max);
        }
    }
};

class SolutionLeetCode
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxPath = INT_MIN;
        dfsMaxPath(root, maxPath);
        return maxPath;
    }

    int dfsMaxPath(TreeNode *root, int &maxPath)
    {
        if (!root) return 0;
        int l = std::max(0, dfsMaxPath(root->left, maxPath));
        int r = std::max(0, dfsMaxPath(root->right, maxPath));
        maxPath = std::max(maxPath, l + r + root->val);
        return root->val + std::max(l, r);
    }
};

int main()
{
    Solution s;

    TreeNode a(1);

    TreeNode b(-2);
    TreeNode c(-3);

    TreeNode d(1);
    TreeNode e(3);
    TreeNode f(-2);

    TreeNode g(-1);

    a.left = &b;
    a.right = &c;

    b.left = &d;
    b.right = &e;

    c.left = &f;

    d.left= &g;

    /*
    TreeNode a(-6);
    TreeNode b(3);
    TreeNode c(2);

    a.right=&b;
    b.left=&c;
    */

    std::cout<<s.maxPathSum(&a)<<std::endl;
    return 0;
}
