#include<iostream>
#include<cassert>
#include<unordered_map>
#include<vector>

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

int main()
{
    Solution s;

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

