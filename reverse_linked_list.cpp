#include<iostream>
#include<cstddef>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int value)
        : val(value)
          , next(nullptr)
    {
    }
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
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

    ListNode* reverseListRec(ListNode* head)
    {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* tail = head->next;
        ListNode* newhead = reverseListRec(head->next);
        tail->next = head;
        return newhead;
    }
};

int main()
{
    ListNode na(2);
    ListNode nb(1);

    na.next = &nb;
    
    Solution s;

    ListNode* ret = s.reverseList(&na);

    std::cout<<ret->val<<std::endl;
}

