#include<iostream>
#include<cassert>


/*
题目作者的解答（英文）
作者双指针法花费的时间比我的方法更少


There are many solutions to this problem:

Brute-force solution (O(mn) running time, O(1) memory):
For each node a i in list A, traverse the entire list B and check if any node
in list B coincides with a i .

Hashset solution (O(n+m) running time, O(n) or O(m) memory):
Traverse list A and store the address / reference to each node in a hash set.
Then check every node b i in list B: if b i appears in the hash set, then b i
is the intersection node.

Two pointer solution (O(n+m) running time, O(1) memory):
Maintain two pointers pA and pB initialized at the head of A and B,
respectively. Then let them both traverse through the lists, one node at a
time. When pA reaches the end of a list, then redirect it to the head of B
(yes, B,that's right.); similarly when pB reaches the end of a list, redirect
it the head of A.
If at any point pA meets pB, then pA/pB is the intersection node.
To see why the above trick would work, consider the following two lists:
A = {1,3,5,7,9,11} and B = {2,4,9,11},
which are intersected at node '9'. Since B.length (=4) < A.length (=6), pB
would reach the end of the merged list first, because pB traverses exactly 2
nodes less than pA does. By redirecting pB to head A, and pA to head B, we now
ask pB to travel exactly 2 more nodes than pA would. So in the second
iteration, they are guaranteed to reach the intersection node at the same time.
If two lists have intersection, then their last nodes must be the same one. So
when pA/pB reaches the end of a list, record the last element of A/B
respectively. If the two last elements are not the same one, then the two
lists have no intersections.
*/

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

