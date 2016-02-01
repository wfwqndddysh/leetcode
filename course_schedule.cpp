#include<iostream>
#include<cassert>
#include<vector>
#include<set>
#include<stack>

class SolutionLeetCodeBFS
{
public:
    bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
    {
        int plen = prerequisites.size();
        std::vector<int> ind(numCourses,0); //indegree vector

        //construct map & get indegree of each vertex
        std::vector<std::vector<bool> > map(numCourses, std::vector<bool>(numCourses, false));
        for (int i=0;i<plen;i++)
        {
            //Important: in case of duplicates in prerequisites, only +1 indegree 
            if (map[prerequisites[i].first][prerequisites[i].second] == false)
            {
                map[prerequisites[i].first][prerequisites[i].second] = true;
                ind[prerequisites[i].first]++;
            }
        }

        //BFS
        std::stack<int> st;
        for (int i=0;i<numCourses;i++)
        {
            if (ind[i]==0) st.push(i);
        }

        int count = 0;// to get the bool result

        while (!st.empty())
        {
            int tmp = st.top();
            st.pop();
            count ++;
            for (int i=0;i<numCourses;i++)
            {
                if (map[i][tmp])
                {
                    ind[i]--;
                    if (ind[i]==0) st.push(i);
                }
            }
        }
        return count < numCourses ? false : true;

    }
};

class SolutionLeetCodeDFS
{
    public:
        bool dfs(int v, std::vector<int> &visit, std::vector<std::set<int>> &graph)
        {
            if (visit[v] == 1){return true;}

            visit[v] = DISCOVERED;
            for (auto it = graph[v].begin(); it != graph[v].end(); it++)
            {
                if (visit[*it] == DISCOVERED || ! dfs(*it, visit, graph))
                {
                    return false;
                }
            }
            visit[v] = PROCCESSED;
            return true;
        }

        bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
        {
            int plen = prerequisites.size();
            std::vector<int> visit(numCourses,UNDISCOVERED);
            std::vector<std::set<int> > graph(numCourses);

            for (int i=0;i<plen;i++)
            {
                graph[prerequisites[i].second].insert(prerequisites[i].first);
            }

            for (int i=0;i<numCourses;i++)
            {
                if (!dfs(i, visit, graph)) return false;
            }
            return true;
        }

    private:
        enum { UNDISCOVERED, DISCOVERED, PROCCESSED };
};

class SolutionBFS
{
public:
    bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
    {
        std::vector<int> ind(numCourses,0); //indegree vector
        std::vector<std::set<int> > dst_src(numCourses);
        std::vector<std::set<int> > src_dst(numCourses);
        for (const auto& pre : prerequisites)
        {
            dst_src[pre.first].insert(pre.second);
            src_dst[pre.second].insert(pre.first);
        }

        for(size_t i=0; i<dst_src.size(); ++i)
            ind[i]=dst_src[i].size();

        //BFS
        std::stack<int> st;
        for (int i=0;i<numCourses;i++)
        {
            if (ind[i]==0) st.push(i);
        }

        int count = 0;// to get the bool result

        while (!st.empty())
        {
            int tmp = st.top();
            st.pop();
            count ++;

            std::set<int>& dst=src_dst[tmp];
            for(auto itr=dst.begin(); itr!=dst.end();)
            {
                ind[*itr]--;
                if (ind[*itr]==0)
                {
                    st.push(*itr);
                    itr=dst.erase(itr);
                }
                else
                {
                    itr++;
                }
            }
        }
        return count < numCourses ? false : true;
    }
};

int main()
{
    SolutionLeetCodeDFS s;

    std::vector<std::pair<int, int>> prerequisites{ {0, 1}, {1, 0} };
    std::cout<<s.canFinish(2, prerequisites)<<std::endl;

    //std::vector<std::pair<int, int>> prerequisites{ {1, 0} };
    //std::cout<<s.canFinish(2, prerequisites)<<std::endl;

    //std::vector<std::pair<int, int>> prerequisites{ {0, 1}, {0, 2}, {1, 2} };
    //std::cout<<s.canFinish(3, prerequisites)<<std::endl;

    return 0;
}

