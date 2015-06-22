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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* cur = head ? head->next : nullptr;
        ListNode* prev = head;

        while(cur)
        {
            if(cur->val!=prev->val)
            {
                prev->next=cur;
                prev = prev->next;
            }
            else
            {
                prev->next = nullptr;
            }
            cur = cur->next;
        }
        return head;
    }
};

int main()
{
    Solution s;

    ListNode a(1);
    ListNode b(2);

    a.next=&b;

    s.deleteDuplicates(&a);

    std::cout<<std::endl;
    return 0;
}

