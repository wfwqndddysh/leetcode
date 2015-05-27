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
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> output;
        if(!root) return output;

        std::stack<TreeNode*> s;
        s.push(root);

        while(!s.empty())
        {
            while(root->left)
            {
                root = root->left;
                s.push(root);
            }

            do
            {
                if(root->right)
                {
                    root = root->right;
                    s.push(root);
                    break;
                }
                else
                {
                    //self
                    output.push_back(root->val);
                    s.pop();

                    TreeNode* child = nullptr;
                    for(child = root; !s.empty(); child=root)
                    {
                        root = s.top();

                        if(root->left==child)
                            break;

                        s.pop();
                        if(root->right==child)
                            output.push_back(root->val);
                    }
                }
            } while(!s.empty());


        }

        return output;
    }

    std::vector<int> postorderTraversal_rec(TreeNode* root)
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

        rec(root->left, output);
        rec(root->right, output);
        output.push_back(root->val);
    }
};

int main()
{
    Solution s;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);

    //c.right = &a;
    //a.left = &b;

    c.left = &a;
    c.right = &b;
    auto v = s.postorderTraversal(&c);
    for(int n : v)
        std::cout<<n<<std::endl;
    return 0;
}

