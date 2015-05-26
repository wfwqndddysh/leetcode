#include<iostream>
#include<cassert>
#include<vector>

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode* n) : val(x), next(n) {}
};

ListNode* make_list(const std::vector<int>& nums)
{
    ListNode* head = nullptr;
    ListNode* cur = head;
    for(auto n : nums)
    {
        ListNode* l = new ListNode(n);
        if(!head)
        {
            head = cur = l;
        }
        else
        {
            cur->next =  l;
            cur = l;
        }
    }
    return head;
}

/*
想到了merge sort， 就可以实现
抽象出了merge_list，

没有想到使用dummy使代码简介
没有继续简化代码抽象出调试了很久的那段代码为split
没有想到使用nullptr来简化代码，而不是始终使用len限定范围
*/
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
            ListNode* tail = new_head;

            bool be_fisrt = true;
            for(size_t i=1; i<=len && next_l; i+=step*2)
            {
                l = r = next_l;
                for(size_t cnt=0; cnt<step && r; ++cnt)
                    r = r->next;

                if(!r) break;

                next_l = r;

                for(size_t cnt=0; cnt<step && next_l; ++cnt)
                    next_l = next_l->next;

                ListNode* new_tail = nullptr;
                auto h = merge_list(l, r, step, &new_tail);
                if(be_fisrt)
                {
                    new_head = h;
                    be_fisrt = false;
                }
                else
                {
                    tail->next = h;
                }
                tail = new_tail;
            }
        }
        return new_head;
    }

    ListNode* merge_list(ListNode* l, ListNode* r, size_t len, ListNode** new_tail)
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

        *new_tail = prev;
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

//一下更加简练的写法来是leetcode
//实际上linux内核里的一个应用，不错

/**
 * Merge sort use bottom-up policy, 
 * so Space Complexity is O(1)
 * Time Complexity is O(NlgN)
 * stable sort
*/
class SolutionLeetCode {
public:
    ListNode *sortList(ListNode *head) {
        if(!head || !(head->next)) return head;

        //get the linked list's length
        ListNode* cur = head;
        int length = 0;
        while(cur){
            length++;
            cur = cur->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode *left, *right, *tail;
        for(int step = 1; step < length; step <<= 1){
            cur = dummy.next;
            tail = &dummy;
            while(cur){
                left = cur;
                right = split(left, step);
                cur = split(right,step);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }
private:
    /**
     * Divide the linked list into two lists,
     * while the first list contains first n ndoes
     * return the second list's head
     */
    ListNode* split(ListNode *head, int n){
        //if(!head) return NULL;
        for(int i = 1; head && i < n; i++) head = head->next;

        if(!head) return NULL;
        ListNode *second = head->next;
        head->next = NULL;
        return second;
    }
    /**
      * merge the two sorted linked list l1 and l2,
      * then append the merged sorted linked list to the node head
      * return the tail of the merged sorted linked list
     */
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
        ListNode *cur = head;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        while(cur->next) cur = cur->next;
        return cur;
    }
};

int main()
{
    Solution s;
    //ListNode* l = make_list({1});
    //ListNode* l = make_list({2, 1});
    //ListNode* l = make_list({3, 2, 1});
    //ListNode* l = make_list({4, 3, 2, 1});
    //ListNode* l = make_list({5, 4, 3, 2, 1});
    //ListNode* l = make_list({6, 5, 4, 3, 2, 1});
    //ListNode* l = make_list({7, 6, 5, 4, 3, 2, 1});
    //ListNode* l = make_list({8, 7, 6, 5, 4, 3, 2, 1});
    //ListNode* l = make_list({9, 8, 7, 6, 5, 4, 3, 2, 1});
    //ListNode* l = make_list({-85,142,41,-17,-71,170,186,183,-21,-76,76});
    ListNode* l = make_list({-84,142,41,-17,-71,170,186,183,-21,-76,76,10,29,81,112,-39,-6,-43,58,41,111,33,69,97,-38,82,-44,-7,99,135,42,150,149,-21,-30,164,153,92,180,-61,99,-81,147,109,34,98,14,178,105,5,43,46,40,-37,23,16,123,-53,34,192,-73,94,39,96,115,88,-31,-96,106,131,64,189,-91,-34,-56,-22,105,104,22,-31,-43,90,96,65,-85,184,85,90,118,152,-31,161,22,104,-85,160,120,-31,144,115});
    auto r = s.sortList(l);
    for(; r; r=r->next)
        std::cout<<r->val<<std::endl;
    return 0;
}

