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

class Solution
{
public:
    ListNode* insertionSortList(ListNode* head)
    {
        auto cur = head;
        head = nullptr;
        while(cur)
        {
            ListNode* node = cur;
            cur = cur->next;
            head = insert(head, node);
        }
        return head;
    }
private:
    ListNode* insert(ListNode* head, ListNode* node)
    {
        if(!head)
        {
            node->next = nullptr;
            return node;
        }

        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur && node->val >= cur->val)
        {
            prev = cur;
            cur = cur->next;
        }

        if(!prev)//follow loc
        {
            node->next = cur;
            head = node;
        }
        else
        {
            prev->next = node;
            node->next = cur;
        }
        return head;
    }
};

int main()
{
    Solution s;
    //ListNode* l = make_list({1});
    //ListNode* l = make_list({1, 1});
    ListNode* l = make_list({2, 1});
    //ListNode* l = make_list({4, 3, 2, 1});
    //ListNode* l = make_list({5, 4, 3, 2, 1});
    //ListNode* l = make_list({6, 5, 4, 3, 2, 1});
    //ListNode* l = make_list({7, 6, 5, 4, 3, 2, 1});
    //ListNode* l = make_list({8, 7, 6, 5, 4, 3, 2, 1});
    //ListNode* l = make_list({9, 8, 7, 6, 5, 4, 3, 2, 1});
    //ListNode* l = make_list({-85,142,41,-17,-71,170,186,183,-21,-76,76});
    auto r = s.insertionSortList(l);
    for(; r; r=r->next)
        std::cout<<r->val<<std::endl;
    return 0;
}

