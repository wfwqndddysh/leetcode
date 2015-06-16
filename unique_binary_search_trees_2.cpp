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
    std::vector<TreeNode*> generateTrees(int n)
    {
        std::vector<TreeNode*> trees;
        rec(1, n, trees);
        return trees;
    }

private:
    void rec(int beg, int end, std::vector<TreeNode*>& trees)
    {
        if(beg==end) return 1;
        if(beg+1==end) return 2;

        int num = 0;
        for(int i=beg; i<=end; ++i)
        {
            if(i==beg)
            {
                std::vector<TreeNode*> new_trees;
                num += rec(beg+1, end, new_trees);
            }
            else if(i==end)
            {
                num += rec(beg, end-1);
            }
            else
            {
                num = num + rec(beg, i-1) * rec(i+1, end);
            }
        }
        return num;
    }

    void build_tree(int a, int b, std::vector<TreeNode*> trees)
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

    void build_tree(int a, std::vector<TreeNode*> trees)
    {
        trees.push_back(new TreeNode(a));
    }
};

class SolutionRec
{
public:
    int numTrees(int n)
    {
        return rec(1, n);
    }

private:
    int rec(int beg, int end)
    {
        if(beg==end) return 1;
        if(beg+1==end) return 2;

        int num = 0;
        for(int i=beg; i<=end; ++i)
        {
            if(i==beg)
                num += rec(beg+1, end);
            else if(i==end)
                num += rec(beg, end-1);
            else
            {
                num = num + rec(beg, i-1) * rec(i+1, end);
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    s.generateTrees(3);
    std::cout<<std::endl;
    return 0;
}

