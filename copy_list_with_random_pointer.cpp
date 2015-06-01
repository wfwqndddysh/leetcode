#include<iostream>
#include<cassert>
#include<unordered_map>
#include<vector>

/*
有一点需要注意，非hash方法处理不了链表有循环的情况;
如果真要用非hash方法处理，遇到循环点时需要停止copy
*/

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        auto r = head;
        auto l = copy_forward(r);

        std::unordered_map<RandomListNode*, size_t> r_ptr2index;
        std::vector<RandomListNode*> l_index2ptr;

        generate_ptr_to_index(r, r_ptr2index);
        generate_index_to_ptr(l, l_index2ptr);

        return copy_random(r, r_ptr2index, l, l_index2ptr);
    }

private:
    void generate_ptr_to_index(RandomListNode* head
            , std::unordered_map<RandomListNode*, size_t>& ptr2index)
    {
        for(size_t i=0; head; ++i)
        {
            ptr2index.insert(std::make_pair(head, i));
            head = head->next;
        }
    }

    void generate_index_to_ptr(RandomListNode* head
            , std::vector<RandomListNode*>& index2ptr)
    {
        for(size_t i=0; head; ++i)
        {
            index2ptr.push_back(head);
            head = head->next;
        }
    }

    RandomListNode* copy_forward(RandomListNode* head)
    {
        RandomListNode dummy(0);
        auto cur = &dummy;

        while(head)
        {
            auto r = new RandomListNode(head->label);
            cur->next = r;
            cur = r;
            head = head->next;
        }
        return dummy.next;
    }

    RandomListNode* copy_random(const RandomListNode* r
            , const std::unordered_map<RandomListNode*, size_t>& r_ptr2index
            , RandomListNode* l
            , const std::vector<RandomListNode*>& l_index2ptr)
    {
        auto head = l;
        for(; r && l; r=r->next, l=l->next)
        {
            if(r->random)
            {
                auto index = r_ptr2index.find(r->random)->second;
                l->random = l_index2ptr[index];
            }
        }
        return head;
    }
};

class SolutionLeetCode
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        copy_to_follow(head);
        copy_random(head);
        return get_follow(head);
    }

private:
    void copy_to_follow(RandomListNode* head)
    {
        while(head)
        {
            auto next = head->next;
            auto l = new RandomListNode(head->label);
            head->next = l;
            l->next = next;
            head = next;
        }
    }

    void copy_random(RandomListNode* head)
    {
        auto l_head = head ? head->next : head;
        while(l_head)
        {
            l_head->random = head->random ? head->random->next : nullptr;
            head = head->next->next;
            l_head = l_head->next ? l_head->next->next : nullptr;
        }
    }

    RandomListNode* get_follow(RandomListNode* head)
    {
        auto l_head = head ? head->next : head;
        auto ret = l_head;
        while(l_head)
        {
            head->next = head->next->next;
            head = head->next;

            l_head->next = l_head->next ? l_head->next->next : nullptr;
            l_head = l_head->next;
        }

        return ret;
    }
};

class SolutionLeetCodeCpp
{
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead, *l1, *l2;
        if (head == NULL) return NULL;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }

        newHead = head->next;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            if (l1->random != NULL) l1->next->random = l1->random->next;
        }

        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != NULL) l2->next = l2->next->next;
        }

        return newHead;
    }
};

int main()
{
    SolutionLeetCode s;

    RandomListNode a(-1);
    RandomListNode b(-1);
    RandomListNode c('#');

    a.next = &b;
    b.next = &c;
    auto l = s.copyRandomList(&a);

    for(; l; l=l->next)
    {
        std::cout<<l->label<<std::endl;
    }

    return 0;
}

