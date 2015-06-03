#include<iostream>
#include<cassert>
#include<vector>
#include<unordered_map>
#include<map>

struct UndirectedGraphNode
{
    int label;
    std::vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if(!node) return nullptr;

        std::unordered_map<int, std::pair<int, int>> label_loc_map;
        std::map<std::pair<int, int>, UndirectedGraphNode*> loc_label_map;
        return copy(node, 0, 0, label_loc_map, loc_label_map);
    }

private:
    UndirectedGraphNode* copy(UndirectedGraphNode* r
            , int deep
            , int index
            , std::unordered_map<int, std::pair<int, int>>& label_loc_map
            , std::map<std::pair<int, int>, UndirectedGraphNode*>& loc_label_map)
    {
        auto itr=label_loc_map.find(r->label);
        if(itr!=label_loc_map.cend())
            return loc_label_map[itr->second];

        auto l = new UndirectedGraphNode(r->label);
        label_loc_map.insert({r->label, {deep, index}});
        loc_label_map.insert({{deep, index}, l});

        for(size_t i=0; i<r->neighbors.size(); ++i)
        {
            l->neighbors.push_back(copy(r->neighbors[i], deep+1, i, label_loc_map, loc_label_map));
        }
        return l;
    }
};

int main()
{
    Solution s;
    UndirectedGraphNode a(0);
    a.neighbors.resize(2, &a);
    std::cout<<s.cloneGraph(&a)<<std::endl;
    return 0;
}

