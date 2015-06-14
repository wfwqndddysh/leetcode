#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

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
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
    {
        if(inorder.size()==0) return nullptr;

        int root_val = postorder.back();
        TreeNode* root = new TreeNode(root_val);

        size_t r_sz=0;
        std::vector<int> r_inorder;
        for(int i=inorder.size()-1; inorder[i]!=root_val; --i, ++r_sz)
        {
            r_inorder.insert(r_inorder.cbegin(), inorder[i]);
        }

        std::vector<int> r_postorder(r_sz);
        for(size_t i=0 ; i<r_sz; ++i)
        {
            r_postorder[i] = postorder[postorder.size()-r_sz-1+i];
        }

        root->right = buildTree(r_inorder, r_postorder);


        size_t l_sz = inorder.size()-r_sz-1;
        std::vector<int> l_inorder;
        for(size_t i=0; i<l_sz; ++i)
        {
            l_inorder.push_back(inorder[i]);
        }

        std::vector<int> l_postorder;
        for(size_t i=0; i<l_sz; ++i)
        {
            l_postorder.push_back(postorder[i]);
        }

        root->left= buildTree(l_inorder, l_postorder);

        return root;
    }
};

class SolutionRef
{
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
    {
        return rec(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

private:
    TreeNode* rec(std::vector<int>& inorder
            , size_t inorder_beg
            , size_t inorder_end
            , std::vector<int>& postorder
            , size_t postorder_beg
            , size_t postorder_end)
    {
        if(inorder_beg>=inorder_end) return nullptr;

        int root_val = postorder[postorder_end-1];
        TreeNode* root = new TreeNode(root_val);

        size_t r_sz=0;
        for(int i=inorder_end-1; inorder[i]!=root_val; --i) r_sz++;
        root->right = rec(inorder
                , inorder_end-r_sz
                , inorder_end
                , postorder
                , postorder_end-r_sz-1
                , postorder_end-1);

        size_t l_sz = inorder_end-inorder_beg-r_sz-1;
        std::vector<int> l_postorder;
        root->left = rec(inorder
                , inorder_beg
                , inorder_beg+l_sz
                , postorder
                , postorder_beg
                , postorder_beg+l_sz);

        return root;
    }
};

int main()
{
    SolutionRef s;
    std::vector<int> inorder{6,4,7,2,8,5,9,1,3};
    std::vector<int> postorder{6,7,4,8,9,5,2,3,1};
    TreeNode* tree = s.buildTree(inorder, postorder);
    TreeNode::print(tree);
    std::cout<<std::endl;
    return 0;
}

