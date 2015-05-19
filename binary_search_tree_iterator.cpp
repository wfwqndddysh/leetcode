#include<iostream>
#include<stack>
#include<cassert>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        push_left_branch(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !left_.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        auto cur = left_.top();
        int val = cur->val;
        left_.pop();
        push_left_branch(cur->right);
        return val;
    }

    void push_left_branch(TreeNode* root)
    {
        if(!root)
        {
            return;
        }

        left_.push(root);
        while(root->left)
        {
            root = root->left;
            left_.push(root);
        }
    }

private:
    std::stack<TreeNode*> left_;
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
    BSTIterator bst_itr(nullptr);

    while(bst_itr.hasNext())
        std::cout<<bst_itr.next()<<std::endl;
    return 0;
}
