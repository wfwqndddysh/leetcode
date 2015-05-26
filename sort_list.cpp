#include<iostream>
#include<cassert>

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode* n) : val(x), next(n) {}
 };

class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        ListNode* new_head = head;
        size_t len = get_len(head);

        for(size_t step=1; step<len; step*=2)
        {
            ListNode* l = new_head;
            ListNode* r = new_head;
            ListNode* next_l = new_head;
            ListNode* last = new_head;

            bool be_fisrt = true;
            for(size_t i=1; i<=len && next_l; i*=step*2)
            {
                l = r = next_l;
                for(size_t cnt=0; cnt<step && r; ++cnt)
                    r = r->next;

                if(!r) break;

                next_l = r;

                for(size_t cnt=0; cnt<step && next_l; ++cnt)
                    next_l = next_l->next;

                ListNode* new_last = nullptr;
                auto h = merge_list(l, r, step, &new_last);
                if(be_fisrt)
                {
                    new_head = h;
                    be_fisrt = false;
                }
                else
                {
                    last->next = h;
                }
                last = new_last;
            }
        }
        return new_head;
    }

    ListNode* merge_list(ListNode* l, ListNode* r, size_t len, ListNode** new_last)
    {
        ListNode* head = nullptr;
        ListNode* prev = nullptr;

        size_t l_i = 0;
        size_t r_i = 0;
        for(; (l_i<len && r_i<len) && r; )
        {
            if(r->val<l->val)
            {
                if(prev)
                    prev->next = r;
                prev = r;
                if(!head)
                    head = prev;

                r = r->next;
                r_i++;
            }
            else
            {
                if(prev)
                    prev->next = l;
                prev = l;
                if(!head)
                    head = prev;

                l = l->next;
                l_i++;
            }
        }

        for(; l_i<len; l_i++)
        {
            prev->next = l;
            prev = l;
            l = l->next;
        }
        for(; r_i<len && r; r_i++)
        {
            prev->next = r;
            prev = r;
            r = r->next;
        }
        prev->next = r;

        *new_last = prev;
        return head;
    }

    size_t get_len(const ListNode* head)
    {
        size_t len = 0;
        while(head)
        {
            head=head->next;
            len++;
        }
        return len;
    }
};

int main()
{
    Solution s;

    /*
    ListNode a(1);
    ListNode b(2, &a);
    ListNode a(4);
    ListNode b(2, &a);
    ListNode c(3, &b);
    auto l = s.sortList(&c);
    */

    ListNode a(1);
    ListNode b(2, &a);
    ListNode c(-3, &b);
    ListNode d(4, &c);
    ListNode e(-5, &d);
    ListNode f(6, &e);
    ListNode g(-10000, &g);
    auto l = s.sortList(&g);
    for(; l; l=l->next)
        std::cout<<l->val<<std::endl;
    return 0;
}

