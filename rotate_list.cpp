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
    ListNode* rotateRight(ListNode* head, int k)
    {
        int len=0;
        for(auto l=head; l; l=l->next) len++;
        if(len<2) return head;

        k = k % len;
        if(k==0) return head;
        int right_len=len-k;

        ListNode* left = nullptr;
        ListNode* right_last = nullptr;
        ListNode* l = head;

        for(int i=0; i<=right_len; ++i)
        {
            right_last = left;
            left = l;
            l = l->next;
        }

        right_last->next = nullptr;
        l = left;

        for(; left->next!=nullptr; left=left->next) ;
        left->next=head;

        return l;
    }
};

int main()
{
    Solution s;
    ListNode a(1);
    ListNode b(2);
    a.next=&b;

    s.rotateRight(&a, 1);
    std::cout<<std::endl;
    return 0;
}

