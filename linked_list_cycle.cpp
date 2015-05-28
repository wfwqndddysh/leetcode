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
    bool hasCycle(ListNode *head)
    {
        if(!head || !head->next || !head->next->next)
            return false;

        auto slow = head;
        auto fast = head->next->next;

        while(fast && slow!=fast)
        {
            slow = slow->next;
            fast = fast->next ? fast->next->next: fast->next;
        }

        return slow==fast;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

