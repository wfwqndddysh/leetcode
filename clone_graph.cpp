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

class Solution_2
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr) return node;
        
        UndirectedGraphNode* cur = new UndirectedGraphNode(node->label);
        labels_.insert(std::make_pair(cur->label, cur));
        
        for(auto itr=node->neighbors.begin(); itr!=node->neighbors.end(); ++itr)
        {
            if(labels_.count((*itr)->label)>0)
            {
                cur->neighbors.push_back(labels_[(*itr)->label]);
            }
            else
            {
                cur->neighbors.push_back(cloneGraph(*itr));
            }
        }
        
        return cur;
    }
private:
    std::unordered_map<int, UndirectedGraphNode*> labels_;
};

class SolutionLeetCode
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if(!node) return node;

        auto itr=r2l_.find(node);
        if(itr!=r2l_.cend())
            return itr->second;

        auto l = new UndirectedGraphNode(node->label);
        r2l_[node] = l;
        for(auto r : node->neighbors)
        {
            l->neighbors.push_back(cloneGraph(r));
        }

        return l;
    }
private:
    std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> r2l_;
};

int main()
{
    Solution s;
    UndirectedGraphNode a(0);
    a.neighbors.resize(2, &a);
    std::cout<<s.cloneGraph(&a)<<std::endl;
    return 0;
}

