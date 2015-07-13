#include<iostream>
#include<cassert>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        if(!head || !head->next) return true;
        if(!head->next->next) return head->val==head->next->val;

        ListNode* slow=head;
        ListNode* fast=head->next->next;

        ListNode* left=nullptr;
        ListNode* right=slow->next;

        while(fast)
        {
            if(fast->next)
            {
                slow=slow->next;
            }
            fast=fast->next ? fast->next->next : fast->next;
            right=right->next;
        }

        slow->next=nullptr;
        left = reverse_list(head);

        while(left && right)
        {
            if(left->val!=right->val)
                return false;

            left=left->next;
            right=right->next;
        }

        return true;
    }

private:
    ListNode* reverse_list(ListNode* head)
    {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* ret = nullptr;

        while(current)
        {
            ret = current;
            current = current->next;
            ret->next = prev;
            prev = ret;
        }
        return ret;
    }
};

int main()
{
    Solution s;

    /*
    ListNode a(1);
    ListNode b(2);
    a.next=&b;
    */

    /*
    ListNode a(1);
    ListNode b(0);
    ListNode c(0);
    a.next=&b;
    b.next=&c;
    */

    ListNode a(1);
    ListNode b(2);
    ListNode c(2);
    ListNode d(1);
    a.next=&b;
    b.next=&c;
    c.next=&d;

    std::cout<<s.isPalindrome(&a)<<std::endl;
    return 0;
}

