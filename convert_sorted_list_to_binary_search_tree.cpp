#include<iostream>
#include<cassert>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode* sortedListToBST(ListNode* head)
    {
        if(!head) return nullptr;

        ListNode* l_left(nullptr);
        ListNode* l_right(nullptr);
        partition(head, l_left, l_right);

        auto t_left = sortedListToBST(l_left);
        auto t_right = sortedListToBST(l_right);

        return merge(head, t_left, t_right);
    }
private:
    void partition(ListNode*& root, ListNode*& left, ListNode*& right)
    {
        auto* pre_low = root;
        auto* low = root;
        auto* fast = root;

        if(!root || !root->next)
            return;

        if(!root->next->next)
        {
            left=nullptr;
            right=root->next;
            return;
        }

        for(; fast && fast->next && fast->next->next; )
        {
            pre_low=low;
            low = low->next;
            fast = fast->next->next;
        }

        left=root;
        root=low;
        right=low->next;
        pre_low->next=nullptr;
    }

    TreeNode* merge(ListNode* head, TreeNode* left, TreeNode* right)
    {
        TreeNode* root=new TreeNode(head->val);
        root->left=left;
        root->right=right;
        return root;
    }
};

int main()
{
    Solution s;
    ListNode a(3);
    ListNode b(5);
    ListNode c(8);

    a.next=&b;
    b.next=&c;

    s.sortedListToBST(&a);

    std::cout<<std::endl;
    return 0;
}

