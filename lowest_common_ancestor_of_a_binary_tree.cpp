#include<iostream>
#include<cassert>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return nullptr;
        assert(p && q);

        std::stack<TreeNode*> ancestor;

        //find p or q
        TreeNode* one=find_first(root, p, q, ancestor);
        auto another=one->val==p->val ? q : p;

        if(contains(one->left, another) || contains(one->right, another)) return one;

        while(!ancestor.empty())
        {
            TreeNode* a=ancestor.top();

            if(a->right!=one)
            {
                std::stack<TreeNode*> ancestor_next;
                auto next=find_first(a->right, p, q, ancestor_next);
                if(next->val==another->val) return a;
                else
                {
                    ancestor=std::move(ancestor_next);
                    continue;
                }
            }

            one=a;
            ancestor.pop();
        }

        return nullptr;
    }

private:
    TreeNode* find_first(TreeNode* root, TreeNode* p, TreeNode* q, std::stack<TreeNode*>& ancestor)
    {
        if(!root) return nullptr;
        if(p->val==root->val || q->val==root->val)
        {
            return root;
        }
        else
        {
            ancestor.push(root);
            size_t sz=ancestor.size();
            TreeNode* t=find_first(root->left, p, q, ancestor);
            if(t)
            {
                return t;
            }
            else
            {
                while(ancestor.size()>sz) ancestor.pop();
                return find_first(root->right, p, q, ancestor);
            }
        }
    }

    bool contains(TreeNode* root, TreeNode* another)
    {
        if(!root) return false;
        return root->val==another->val || contains(root->left, another) || contains(root->right, another);
    }
};

int main()
{
    Solution s;

    [37,-34,-48,null,-100,-100,48,null,null,null,null,-54,null,-71,-22,null,null,null,8], node with value -100, node with value -71

    std::cout<<std::endl;
    return 0;
}

