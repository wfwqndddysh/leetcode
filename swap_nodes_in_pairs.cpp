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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* left=head;
        ListNode* prev_first=nullptr;
        ListNode* prev_second=nullptr;

        ListNode* cur_first=nullptr;
        ListNode* cur_second=nullptr;

        while(left && left->next)
        {
            cur_second=left;
            cur_first=left->next;

            left=left->next->next;

            cur_first->next=cur_second;
            cur_second->next=left;

            if(prev_second)
            {
                prev_second->next=cur_first;
                prev_second=cur_second;
            }
            else
            {
                prev_first=cur_first;
                prev_second=cur_second;
            }
        }

        return prev_first ? prev_first : head;
    }
};

int main()
{
    Solution s;

    ListNode a(5);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(6);
    ListNode f(2);
    ListNode g(2);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;
    e.next=&g;

    s.swapPairs(&a);
        
    std::cout<<std::endl;
    return 0;
}

