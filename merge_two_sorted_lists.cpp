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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* res=nullptr;
        ListNode* prev=nullptr;
        while(l1 && l2)
        {
            ListNode* cur=nullptr;
            if(l2->val<l1->val)
            {
                cur=l2;
                l2=cur->next;
            }
            else
            {
                cur=l1;
                l1=cur->next;
            }

            if(!res)
            {
                res=cur;
                prev=res;
            }
            else
            {
                prev->next=cur;
                prev=cur;
            }
        }

        if(prev) prev->next=l1 ? l1 : l2;
        else res=l1 ? l1 : l2;

        return res;
    }
};

int main()
{
    Solution s;

    ListNode a(2);
    ListNode b(1);

    s.mergeTwoLists(&a, &b);

    std::cout<<std::endl;
    return 0;
}

