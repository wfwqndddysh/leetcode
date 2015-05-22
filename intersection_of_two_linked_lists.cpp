#include<iostream>
#include<cassert>


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution
{
public:
    const ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        size_t len_a = 0;
        size_t len_b = 0;
        for(ListNode* tmp_a=headA;tmp_a!=nullptr; tmp_a=tmp_a->next, len_a++);
        for(ListNode* tmp_b=headB;tmp_b!=nullptr; tmp_b=tmp_b->next, len_b++);

        //make a and b has same len
        for(;len_a>len_b; len_a--)
        {
            headA = headA->next;
        }
        for(;len_b>len_a; len_b--)
        {
            headB = headB->next;
        }

        while(headA!=headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

    //leetcode 看起来简单，但是时间复杂度并不比上面的低
    ListNode *getIntersectionNode_(ListNode *headA, ListNode *headB)
    {
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA != ptrB)
        {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        return ptrA;
    }
};

int main()
{
    ListNode a(1);
    ListNode b(2, &a);
    ListNode c(3, &b);
    ListNode d(4, &c);
    ListNode e(5, &d);
    ListNode f(6, &e);
    ListNode g(7, &e);
    ListNode h(8, &g);
    ListNode i(9, &h);

    ListNode o(11, &c);
    ListNode p(12, &o);

    Solution s;
    std::cout<<s.getIntersectionNode_(&p, &i)->val<<std::endl;
    return 0;
}

