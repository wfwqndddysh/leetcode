#include<iostream>
#include<cassert>
#include<vector>
#include<unordered_map>

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
private:
    void label2loc(UndirectedGraphNode* node
            , int deep
            , int index
            , std::unordered_map<int, std::pair<int, int>> label_loc_map)
    {
        if(label_loc_map.count(node->label)>0)
            return;

        label_loc_map.insert({node->label, {deep, index}});
        for(size_t i=0; i<node->neighbors.size(); ++i)
        {
            label2loc(node->neighbors[i], deep+1, i, label_loc_map);
        }
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

