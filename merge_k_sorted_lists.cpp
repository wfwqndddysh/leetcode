#include<iostream>
#include<cassert>
#include<vector>
#include<list>
#include<algorithm>
#include<climits>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        ListNode* res=nullptr;
        ListNode* prev=nullptr;

        std::vector<ListNode*> heap;
        for(size_t i=0; i<lists.size(); ++i) if(lists[i]) heap.push_back(lists[i]);

        auto comp=[](ListNode* l, ListNode* r)
            { return l->val>r->val; };

        std::make_heap(heap.begin(), heap.end(), comp);

        while(!heap.empty())
        {
            auto cur=heap[0];

            if(prev)
            {
                prev->next=cur;
                prev=cur;
            }
            else
            {
                res=cur;
                prev=res;
            }

            std::pop_heap(heap.begin(), heap.end(), comp);
            heap.pop_back();

            if(cur->next)
            {
                heap.push_back(cur->next);
                std::push_heap(heap.begin(), heap.end(), comp);
            }
        }

        return res;
    }
};

int main()
{
    Solution s;

    ListNode a(1);
    ListNode b(2);
    ListNode c(2);
    a.next=&b;
    b.next=&c;

    ListNode d(1);
    ListNode e(1);
    ListNode f(2);
    d.next=&e;
    e.next=&f;

    std::vector<ListNode*> lists{ &a, &d };
    s.mergeKLists(lists);

    std::cout<<std::endl;
    return 0;
}

