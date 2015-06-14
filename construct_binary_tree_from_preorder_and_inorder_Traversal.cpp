#include<iostream>
#include<cassert>
#include<vector>

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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        return rec(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

private:
    TreeNode* rec(std::vector<int>& preorder
            , size_t preorder_beg
            , size_t preorder_end
            , std::vector<int>& inorder
            , size_t inorder_beg
            , size_t inorder_end)
    {
        if(preorder_beg>=preorder_end) return nullptr;

        int root_val = preorder[preorder_beg];
        TreeNode* root = new TreeNode(root_val);

        size_t l_sz=0;
        for(int i=inorder_beg; inorder[i]!=root_val; ++i) l_sz++;
        root->left = rec(preorder
                , preorder_beg+1
                , preorder_beg+l_sz+1
                , inorder
                , inorder_beg
                , inorder_beg+l_sz);

        root->right = rec(preorder
                , preorder_beg+1+l_sz
                , preorder_end
                , inorder
                , inorder_beg+1+l_sz
                , inorder_end);

        return root;
    }
};

int main()
{
    Solution s;
    std::vector<int> preorder{1, 2};
    std::vector<int> inorder{2, 1};
    auto tree=s.buildTree(preorder, inorder);
    TreeNode::print(tree);
    std::cout<<std::endl;
    return 0;
}

