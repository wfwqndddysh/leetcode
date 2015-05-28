#include<iostream>
#include<cassert>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* detectCycle(ListNode *head)
    {
        if(!head || !head->next || !head->next->next)
            return nullptr;

        auto slow = head->next;
        auto fast = head->next->next;

        while(fast && slow!=fast)
        {
            slow = slow->next;
            fast = fast->next ? fast->next->next: fast->next;
        }

        if(slow!=fast)
            return nullptr;

        // 2*(a+b+mc) = a+b+nc ====> a = nc-2mc-b;
        for(fast = head; fast != slow; fast = fast->next)
            slow = slow->next;

        return slow;
    }
};

int main()
{
    Solution s;
    ListNode d(4);
    ListNode c(2);
    ListNode b(0);
    ListNode a(3);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &b;

    std::cout<<s.detectCycle(&d)<<std::endl;
    return 0;
}

