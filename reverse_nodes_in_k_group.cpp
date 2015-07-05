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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(k<2) return head;

        ListNode* res=nullptr;
        ListNode* left=head;
        ListNode* last_tail=nullptr;
        while(left)
        {
            ListNode* cur=left;
            ListNode* last=nullptr;
            int cnt=0;
            for(; left && cnt<k; ++cnt)
            {
                last=left;
                left=left->next;
            }
            last->next=nullptr;

            if(cnt==k)
            {
                ListNode* l=reverse_list(cur, last_tail);
                if(!res) res=l;
            }
            else
            {
                if(last_tail) last_tail->next=cur;
                if(!res) res=cur;
            }
        }

        return res;
    }

private:
    ListNode* reverse_list(ListNode* head, ListNode*& last_tail)
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

        if(last_tail) last_tail->next=ret;
        last_tail=head;
        
        return ret;
    }
};

int main()
{
    Solution s;

    /*
    ListNode a(1);
    ListNode b(2);

    a.next=&b;
    s.reverseKGroup(&a, 1);
    */

    /*
    ListNode a(1);
    s.reverseKGroup(&a, 2);
    */

    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);

    a.next=&b;
    b.next=&c;
    c.next=&d;

    s.reverseKGroup(&a, 2);

    std::cout<<std::endl;
    return 0;
}

