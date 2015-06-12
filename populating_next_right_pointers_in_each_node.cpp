#include<iostream>
#include<cassert>


struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        auto cur_level = root;
        auto next_level = cur_level ? (cur_level->left ? cur_level->left : cur_level->right) : nullptr;

        while(next_level)
        {
            auto tmp = next_level;
            for(; cur_level; cur_level=cur_level->next)
            {
                if(cur_level->left)
                {
                    next_level->next = cur_level->left;
                    next_level = next_level->next;
                }
                if(cur_level->right)
                {
                    next_level->next = cur_level->right;
                    next_level = next_level->next;
                }
            }
            cur_level = tmp;
            next_level = tmp->left ? tmp->left : tmp->right;
        }
    }
};

int main()
{
    Solution s;

    TreeLinkNode a(1);
    TreeLinkNode b(2);
    a.right=&b;

    s.connect(&a);

    std::cout<<std::endl;
    return 0;
}

