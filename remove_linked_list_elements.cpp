struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int value)
        : val(value)
          , next(nullptr)
    {
    }
};

class Solution
{
public:
    ListNode* remove_elements(ListNode* head, int val)
    {
        ListNode* cur = head;
        head = nullptr;
        ListNode* pre = nullptr;

        for(; cur!=nullptr; cur=cur->next)
        {
            if(cur->val==val)
            {
                delete cur;
                continue;
            }

            if(head==nullptr)
            {
                head = cur;
            }

            if(pre!=nullptr)
            {
                pre->next = cur;
            }
            pre = cur;
        }

        if(pre!=nullptr)
        {
            pre->next = nullptr;
        }
        return head;
    }

    ListNode* remove_elements_second_level(ListNode* head, int val)
    {
        ListNode** p_cur  = &head;
        while (*p_cur != nullptr)
        {
            if ((*p_cur)->val == val)
            {
                ListNode* del_node = *p_cur;
                *p_cur = (*p_cur)->next;
                delete del_node;
            }
            else
            {
                p_cur = &((*p_cur)->next);
            }
        }
        return head;
    }
};

int main()
{
    Solution s;

    ListNode a(1);
    ListNode b(2);
    ListNode c(3);

    a.next=&b;
    b.next=&c;

    s.remove_elements_second_level(&a, 2);

    return 0;
}

