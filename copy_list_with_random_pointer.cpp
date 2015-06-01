#include<iostream>
#include<cassert>

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
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

