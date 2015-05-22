#include<iostream>
#include<cassert>


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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

        while(headA!=headB && headA!=nullptr && headB!=nullptr)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}


