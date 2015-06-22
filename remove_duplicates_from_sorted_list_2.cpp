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
        ListNode* cur = head;
        head = nullptr;
        ListNode* prev = nullptr;

        while(cur)
        {
            ListNode* next = find_next(cur);
            if(next)
            {
                if(!prev)
                {
                    head = prev = next;
                }
                else
                {
                    prev->next = next;
                    prev = prev->next;
                }
                cur = next->next;
            }
            else
            {
                if(prev)
                    prev->next = nullptr;
                break;
            }
        }
        return head;;
    }
private:
    ListNode* find_next(ListNode* cur)
    {
        size_t cnt=1;
        int val = cur->val;
        for(; cur->next; )
        {
            if(cur->next->val!=val)
            {
                if(cnt==1)
                    return cur;
                else
                {
                    val=cur->next->val;
                    cnt=0;
                }
            }
            cur=cur->next;
            ++cnt;
        }
        return cnt==1 ? cur : nullptr;
    }
};

int main()
{
    Solution s;

    /*
    ListNode a(1);
    */

    ListNode a(1);
    ListNode b(1);
    ListNode c(2);
    a.next=&b;
    b.next=&c;

    /*
    ListNode a(1);
    ListNode b(1);
    ListNode c(2);
    ListNode d(2);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    */

    s.deleteDuplicates(&a);

    std::cout<<std::endl;
    return 0;
}

