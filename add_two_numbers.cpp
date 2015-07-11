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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* res=nullptr;
        ListNode* prev=nullptr;
        int d=0;

        while(l1 && l2)
        {
            int r=(l1->val+l2->val+d)%10;
            d=(l1->val+l2->val+d)/10;

            if(!res)
            {
                l1->val=r;
                res=l1;
                prev=res;
            }
            else
            {
                l1->val=r;
                prev->next=l1;
                prev=l1;
            }

            l1=l1->next;
            l2=l2->next;

            prev->next=nullptr;
        }

        while(l1)
        {
            int r=(l1->val+d)%10;
            d=(l1->val+d)/10;

            if(!res)
            {
                l1->val=r;
                res=l1;
                prev=res;
            }
            else
            {
                l1->val=r;
                prev->next=l1;
                prev=l1;
            }

            if(d==0) break;

            l1=l1->next;
        }

        while(l2)
        {
            int r=(l2->val+d)%10;
            d=(l2->val+d)/10;

            if(!res)
            {
                l2->val=r;
                res=l2;
                prev=res;
            }
            else
            {
                l2->val=r;
                prev->next=l2;
                prev=l2;
            }

            if(d==0) break;

            l2=l2->next;
        }

        if(d!=0) prev->next=new ListNode(d);

        return res;
    }
};

class SolutionLeetCode
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
};

int main()
{
    Solution s;

    /*
    ListNode a(0);
    ListNode b(1);
    */

    ListNode a(1);
    ListNode b(8);
    a.next=&b;

    ListNode c(0);


    s.addTwoNumbers(&a, &c);

    std::cout<<std::endl;
    return 0;
}

