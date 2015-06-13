#include<iostream>
#include<cassert>
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
    int minDepth(TreeNode* root)
    {
        if(!root) return 0;
        std::queue<TreeNode*> q;
        q.push(root);

        int cnt_of_last_level = 1;
        int cnt_of_cur_level = 0;
        int level = 0;

        bool found_leaf = false;
        while(!q.empty() && !found_leaf)
        {
            auto cur = q.front();
            q.pop();

            if(!cur->left && !cur->right) return level+1;

            if(cur->left)
            {
                q.push(cur->left);
                cnt_of_cur_level++;
            }
            if(cur->right)
            {
                q.push(cur->right);
                cnt_of_cur_level++;
            }

            cnt_of_last_level--;

            if(cnt_of_last_level==0)
            {
                cnt_of_last_level=cnt_of_cur_level;
                cnt_of_cur_level=0;
                level++;
            }
        }
        return level;
    }
};

int main()
{
    Solution s;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left=&b;
    a.right=&c;
    std::cout<<s.minDepth(&a)<<std::endl;
    return 0;
}

