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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* l = nullptr;
        ListNode* l_last = nullptr;
        ListNode* r = nullptr;
        ListNode* r_last = nullptr;

        ListNode* cur = head;
        for(; cur; cur=cur->next)
        {
            if(cur->val<x)
            {
                if(!l)
                {
                    l = l_last = cur;
                }
                else
                {
                    l_last->next = cur;
                    l_last = cur;
                }
            }
            else
            {
                if(!r)
                {
                    r = r_last = cur;
                }
                else
                {
                    r_last->next = cur;
                    r_last = cur;
                }
            }
        }

        if(l_last) l_last->next = r;
        if(r_last) r_last->next = nullptr;
        return l ? l : r;
    }
};

int main()
{
    Solution s;

    ListNode a(1);
    ListNode b(1);
    a.next = &b;

    s.partition(&a, 0);
    std::cout<<std::endl;
    return 0;
}

