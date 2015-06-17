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
        auto head = root;

        while(!s.empty())
        {
            auto cur = s.top();
            bool be_leaf = !cur->left && !cur->right;
            bool be_subtrees_finished = cur->left == head || cur->right == head;

            if(be_leaf || be_subtrees_finished)
            {
                output.push_back(cur->val);
                s.pop();
                head = cur;
            }

            if(root->right)
            {
                s.push(root->right);
            }
            if(root->left)
            {
                s.push(root->left);
            }
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

//leetcode discuss

class SolutionLeetCode
{
public:
    //将前序遍历反转的到的结果，不过既然使用了前序遍历了，就可以先得到前序遍历
    //的结果，最后再反转一次，不用每次都插入前面
    std::vector<int> postorderTraversal(TreeNode *root) {
        std::vector<int> v;
        if (!root) return v;

        std::stack<TreeNode *> s;
        s.push(root);

        TreeNode *p = NULL;
        while(!s.empty()) {
            p = s.top();
            s.pop();
            v.insert(v.begin(), p->val);
            if (p->left) s.push(p->left);
            if (p->right) s.push(p->right);
        }

        return v;
    }
};

class SolutionLeetCode2
{
public:
    //这个思路倒是值得注意一下，它把左右节点push进去之后
    //将其修改为null，相当于做了标记，说明它的左右子树都遍历过了
    //这个算法整体的难度就在于标计和判断节点的左右子树是否已经遍历过了
    std::vector<int> postorderTraversal(TreeNode *root) {
        std::stack<TreeNode*> s;
        std::vector<int> vec;
        if(root == NULL)
            return vec;

        s.push(root);
        while(!s.empty())
        {
            TreeNode* n = s.top();
            if(n->right)
                s.push(n->right);
            if(n->left)
                s.push(n->left);
            n->left = NULL;
            n->right = NULL;

            n = s.top();
            if(n->left == NULL && n->right == NULL)
            {
                vec.push_back(n->val);
                s.pop();
            }
        }
        return vec;
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

