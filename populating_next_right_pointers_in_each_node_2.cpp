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
                if(cur_level->left && next_level!=cur_level->left)
                {
                    next_level->next = cur_level->left;
                    next_level = next_level->next;
                }
                if(cur_level->right && next_level!=cur_level->right)
                {
                    next_level->next = cur_level->right;
                    next_level = next_level->next;
                }
            }

            while(tmp && !tmp->left && !tmp->right)
            {
                tmp=tmp->next;
            }
            if(tmp)
            {
                cur_level = tmp;
                next_level = tmp->left ? tmp->left : tmp->right;
            }
            else break;
        }
    }
};

int main()
{
    Solution s;

    TreeLinkNode a(3);
    TreeLinkNode b(9);
    TreeLinkNode c(20);
    TreeLinkNode d(15);
    TreeLinkNode e(7);

    a.left=&b;
    a.right=&c;

    c.left=&d;
    c.right=&e;

    s.connect(&a);

    std::cout<<std::endl;
    return 0;
}

