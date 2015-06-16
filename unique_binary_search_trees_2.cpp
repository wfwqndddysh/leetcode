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
    std::vector<TreeNode*> generateTrees(int n)
    {
        std::vector<TreeNode*> trees;
        rec(1, n, trees);
        if(trees.empty()) trees.push_back(nullptr);
        return trees;
    }

private:
    void rec(int beg, int end, std::vector<TreeNode*>& trees)
    {
        if(beg==end)
        {
            build_tree(beg, trees);
            return;
        }
        if(beg+1==end)
        {
            build_tree(beg, beg+1, trees);
            return;
        }

        for(int i=beg; i<=end; ++i)
        {
            if(i==beg)
            {
                std::vector<TreeNode*> r;
                rec(beg+1, end, r);
                for(size_t m=0; m<r.size(); ++m)
                {
                    auto root = new TreeNode(i);
                    root->right = r[m];
                    trees.push_back(root);
                }
            }
            else if(i==end)
            {
                std::vector<TreeNode*> l;
                rec(beg, end-1, l);
                for(size_t m=0; m<l.size(); ++m)
                {
                    auto root = new TreeNode(i);
                    root->left = l[m];
                    trees.push_back(root);
                }
            }
            else
            {
                std::vector<TreeNode*> l;
                std::vector<TreeNode*> r;
                rec(beg, i-1, l);
                rec(i+1, end, r);

                for(size_t m=0; m<l.size(); ++m)
                {
                    for(size_t n=0; n<r.size(); ++n)
                    {
                        auto root = new TreeNode(i);
                        root->left = l[m];
                        root->right = r[n];
                        trees.push_back(root);
                    }
                }
            }
        }
    }

    void build_tree(int a, int b, std::vector<TreeNode*>& trees)
    {
        auto t1 = new TreeNode(a);
        auto t2 = new TreeNode(b);
        t1->right=t2;
        auto t3 = new TreeNode(a);
        auto t4 = new TreeNode(b);
        t4->left=t3;
        trees.push_back(t1);
        trees.push_back(t4);
    }

    void build_tree(int a, std::vector<TreeNode*>& trees)
    {
        trees.push_back(new TreeNode(a));
    }
};

int main()
{
    Solution s;
    auto trees = s.generateTrees(3);

    for(auto t : trees)
    {
        TreeNode::print(t);
    }

    std::cout<<std::endl;
    return 0;
}

