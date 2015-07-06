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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(n==0 || !head) return head;

        int cnt=0;
        ListNode* cur=head;
        ListNode* prev=nullptr;

        while(cur)
        {
            if(cnt<n)
                cnt++;
            else if(cnt==n)
            {
                prev=head;
                cnt++;
            }
            else
                prev=prev->next;
            cur=cur->next;
        }
        if(prev)
            prev->next=prev->next->next;
        else
            head=head->next;

        return head;
    }
};

int main()
{
    Solution s;

    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    a.next=&b;
    b.next=&c;

    s.removeNthFromEnd(&a, 1);

    std::cout<<std::endl;
    return 0;
}

