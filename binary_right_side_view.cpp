#include<iostream>
#include<cassert>
#include<vector>

struct TreeNode
{
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}

    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
    std::vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> views;
        //views的size可以代表 need_level的值，省去一个参数
        int need_level = 0;
        right_side_view(views, root, 0, &need_level);
        return views;
    }
private:
    void right_side_view(std::vector<int>& views
            , TreeNode* root
            , int cur_level
            , int* need_level)
    {
        if(!root)
            return;
        if(cur_level>=*need_level)
        {
            views.push_back(root->val);
            *need_level = *need_level + 1;
        }
        right_side_view(views, root->right, cur_level+1, need_level);
        right_side_view(views, root->left, cur_level+1, need_level);
    }
};

int main()
{
    return 0;
}

