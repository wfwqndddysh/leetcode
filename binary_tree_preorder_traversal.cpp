#include<iostream>
#include<cassert>
#include<vector>
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
    std::vector<int> preorderTraversalLeetCode(TreeNode* root)
    {
        std::vector<int> output;
        if(!root) return output;

        std::stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            auto root = s.top();
            s.pop();

            output.push_back(root->val);

            if(root->right)
                s.push(root->right);

            if(root->left)
                s.push(root=root->left);
        }
        return output;
    }

    std::vector<int> preorderTraversal_rec(TreeNode* root)
    {
        std::vector<int> output;
        rec(root, output);
        return output;
    }

private:
    void rec(TreeNode* root, std::vector<int>& output)
    {
        if(!root)
            return;

        output.push_back(root->val);
        rec(root->left, output);
        rec(root->right, output);
    }
};

int main()
{
    Solution s;
    TreeNode a(1);
    auto v = s.preorderTraversalLeetCode(&a);
    for(int n : v)
        std::cout<<n<<std::endl;
    return 0;
}

