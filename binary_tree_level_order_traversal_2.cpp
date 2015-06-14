#include<iostream>
#include<cassert>
#include<vector>
#include<queue>
#include<algorithm>

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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        if(!root) return res;

        std::queue<TreeNode*> q;
        q.push(root);
        res.push_back({});

        int cnt_last_level(1);
        int cnt_cur_level(0);
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();

            if(cur->left)
            {
                q.push(cur->left);
                cnt_cur_level++;
            }
            if(cur->right)
            {
                q.push(cur->right);
                cnt_cur_level++;
            }

            res.back().push_back(cur->val);

            if(--cnt_last_level==0)
            {
                cnt_last_level=cnt_cur_level;
                cnt_cur_level=0;
                res.push_back({});
            }
        }

        if(res.back().empty()) res.pop_back();
        std::reverse(res.begin(), res.end());
        return res;
    }
};

class SolutionRec
{
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        rec(root, 0, res);
        std::reverse(res.begin(), res.end());
        return res;
    }
private:
    void rec(TreeNode* root, size_t level, std::vector<std::vector<int>>& res)
    {
        if(!root) return;

        if(level==res.size())
            res.push_back({});

        res[level].push_back(root->val);

        rec(root->left, level+1, res);
        rec(root->right, level+1, res);
    }
};

int main()
{
    Solution s;
    TreeNode a(1);
    s.levelOrderBottom(&a);
    std::cout<<std::endl;
    return 0;
}

