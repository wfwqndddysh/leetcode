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
    void reorderList(ListNode* head)
    {
        if(!head || !head->next || !head->next->next)
            return;

        auto left = head;
        auto right = reverse(split(head));

        while(left && right)
        {
            auto n = left->next;
            left->next = right;
            right = right->next;
            left->next->next = n;
            left = n;
        }
    }
private:
    ListNode* split(ListNode* head)
    {
        auto slow = head;
        auto fast = head->next->next;

        while(fast)
        {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }
        auto after_half = slow->next;
        slow->next=nullptr;
        return after_half;
    }

    ListNode* reverse(ListNode* head)
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
    std::cout<<std::endl;
    return 0;
}

