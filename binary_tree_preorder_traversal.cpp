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
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> output;
        if(!root) return output;

        std::stack<TreeNode*> s;
        output.push_back(root->val);
        s.push(root);

        while(!s.empty())
        {
            while(root->left)
            {
                root = root->left;
                output.push_back(root->val);
                s.push(root);
            }

            do
            {
                if(root->right)
                {
                    root = root->right;
                    output.push_back(root->val);
                    s.push(root);
                    break;
                }
                else
                {
                    s.pop();
                    for(auto child = root; !s.empty(); child=root)
                    {
                        root = s.top();
                        if(root->right!=child)
                            break;
                        s.pop();
                    }
                }
            } while(!s.empty());
        }
        return output;
    }

    std::vector<int> preorderTraversal_(TreeNode* root)
    {
        std::vector<int> output;
        if(!root) return output;

        std::stack<TreeNode*> s;
        output.push_back(root->val);
        s.push(root);

        while(!s.empty())
        {
            if(!root->left && !root->right)
            {
                //需要判断是否为已经访问过了
                auto child = root;
                s.pop();
                for(; !s.empty(); child = root)
                {
                    root = s.top();

                    if(child!=root->right && child!=root->left)
                    {
                        output.push_back(root->val);
                        break;
                    }
                    s.pop();
                }
                continue;
            }

            if(root->left)
            {
                if(root->right)
                    s.push(root->right);

                output.push_back(root->left->val);
                s.push(root->left);
            }
            else
            {
                output.push_back(root->right->val);
                s.push(root->right);
            }
            root = root->left ? root->left : root->right;
        }
        return output;
    }

    std::vector<int> preorderTraversalLeetCode(TreeNode* root)
    {
        std::vector<int> output;
        if(!root) return output;

        std::stack<TreeNode*> s;

        while(root)
        {
            output.push_back(root->val);

            if(root->right)
                s.push(root->right);

            if(root->left)
                root=root->left;
            else
            {
                if(s.empty())
                    break;
                root = s.top();
                s.pop();
            }
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
    TreeNode b(2);
    TreeNode c(3);

    //c.right = &a;
    //a.left = &b;

    c.left= &a;
    c.right = &b;
    auto v = s.preorderTraversalLeetCode(&a);
    for(int n : v)
        std::cout<<n<<std::endl;
    return 0;
}

