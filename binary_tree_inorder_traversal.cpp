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

    static void print(TreeNode* root)
    {
        if(!root) return;
        std::cout<<root->val<<" ";
        print(root->left);
        print(root->right);
    }
};

class Solution
{
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> output;
        std::stack<TreeNode*> st;

        auto cur = root;
        while(cur)
        {
            st.push(cur);
            cur=cur->left;
        }

        while(!st.empty())
        {
            cur = st.top();
            st.pop();

            output.push_back(cur->val);

            cur = cur->right;
            while(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
        }
        return output;
    }
};

int main()
{
    Solution s;
    TreeNode a(1);
    TreeNode b(2);

    a.left=&b;
    auto v = s.inorderTraversal(&a);
    for(int n : v)
        std::cout<<n<<std::endl;
    return 0;
}

