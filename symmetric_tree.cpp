#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
#include<queue>

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
    bool isSymmetric(TreeNode* root)
    {
        if(!root) return true;

        std::vector<std::pair<TreeNode*, size_t>> bfs;
        bfs.push_back({root, 1});
        size_t level = 0;

        while(!bfs.empty())
        {
            size_t sz=bfs.size();

            if(level>0 && sz%2==1) return false;
            for(size_t i=0; i<sz/2; ++i)
            {
                if(bfs[i].first->val != bfs[sz-i-1].first->val || bfs[i].second+bfs[sz-i-1].second!=((1<<level)+1))
                    return false;
            }

            std::vector<std::pair<TreeNode*, size_t>> v;
            for(size_t i=0; i<sz; ++i)
            {
                auto cur = bfs[i];
                if(cur.first->left)
                {
                    v.push_back({cur.first->left, cur.second*2-1});
                }
                if(cur.first->right)
                {
                    v.push_back({cur.first->right, cur.second*2});
                }
            }
            bfs = std::move(v);
            level++;
        }
        return true;
    }
};

class SolutionLeetCode
{
public:
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *left, *right;
        if (!root)
            return true;

        std::queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty())
        {
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};

class SolutionRec
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if(!root) return true;
        return rec(root->left, root->right);
    }
private:
    bool rec(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return true;

        if(left && right)
        {
            return left->val==right->val && rec(left->left, right->right) && rec(left->right, right->left);
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    /*
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(3);

    a.left = &b;
    a.right = &c;

    b.right = &d;
    c.left = &e;
    */

    /*
    TreeNode a(1);
    TreeNode b(2);
    a.left = &b;
    */

    TreeNode a(2);
    TreeNode b(3);
    TreeNode c(3);
    a.left = &b;
    a.right = &c;

    TreeNode d(4);
    TreeNode e(5);
    b.left = &d;
    b.right = &e;

    TreeNode f(5);
    TreeNode g(4);
    c.left = &f;
    c.right = &g;

    TreeNode h(8);
    TreeNode i(9);
    e.left = &h;
    e.right = &i;

    TreeNode j(9);
    TreeNode k(8);
    f.left = &j;
    f.right = &k;

    s.isSymmetric(&a);
    std::cout<<std::endl;
    return 0;
}

