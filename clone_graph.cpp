#include<iostream>
#include<cassert>
#include<vector>

struct UndirectedGraphNode
{
    int label;
    std::vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

