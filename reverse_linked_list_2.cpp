#include<iostream>
#include<cstddef>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int value) : val(value) , next(nullptr) {}
};

class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode* current = head;
        ListNode* head_last =  nullptr;

        int start=1;
        while(current && start<m)
        {
            head_last = current;
            current = current->next;
            start++;
        }

        ListNode* prev = nullptr;
        ListNode* mid_last = current;
        while(current && m<=n)
        {
            auto tmp = current;
            current = current->next;
            tmp->next = prev;
            prev = tmp;
            m++;
        }

        if(mid_last) mid_last->next = current;
        if(head_last) head_last->next= prev;
        return head_last ? head : prev;
    }
};

int main()
{
    ListNode na(1);
    ListNode nb(2);
    ListNode nc(3);
    na.next=&nb;
    nb.next=&nc;

    /*
    ListNode na(3);
    ListNode nb(5);
    na.next=&nb;
    */

    //ListNode na(5);

    Solution s;
    ListNode* ret = s.reverseBetween(&na, 1, 2);

    std::cout<<ret->val<<std::endl;
}

