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
    ListNode* reverseList(ListNode* head, int m, int n)
    {
        ListNode* current = head;
        ListNode* prev = head;

        int start=1;
        while(current && start<m)
        {
            prev = current;
            current = current->next;
        }

        while(current && m<n)
        {
            auto tmp = current;
            current = current->next;
            tmp->next = prev;
            prev = tmp;
            m++;
        }
        return prev;
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

