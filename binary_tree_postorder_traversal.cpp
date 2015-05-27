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
    std::vector<int> postorderTraversal(TreeNode* root)
    {
    }
}

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

