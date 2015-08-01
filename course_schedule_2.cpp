#include<iostream>
#include<cassert>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>

class SolutionLeetCodeDFS
{
public:
    bool dfs(int v, std::vector<int> &visit, std::vector<std::set<int>> &gr)
    {
        if (visit[v] == 1){return true;}

        visit[v] = -1;
        for (auto it = gr[v].begin(); it != gr[v].end(); it++)
        {
            if (visit[*it] == -1 || ! dfs(*it, visit, gr))
            {
                return false;
            }
        }
        visit[v] = 1;
        res_.push_back(v);
        return true;
    }

    std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
    {
        int plen = prerequisites.size();
        std::vector<int> visit(numCourses,0);
        std::vector<std::set<int> > gr(numCourses);

        for (int i=0;i<plen;i++)
        {
            gr[prerequisites[i].second].insert(prerequisites[i].first);
        }

        for (int i=0;i<numCourses;i++)
        {
            if (!dfs(i, visit, gr)) return {};
        }
        std::reverse(res_.begin(), res_.end());
        return res_;
    }

private:
    std::vector<int> res_;
};

class SolutionBFS
{
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
    {
        std::vector<int> res;

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
            res.push_back(tmp);

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
        return count < numCourses ? std::vector<int>{} : res;
    }
};

int main()
{
    SolutionBFS s;

    //std::vector<std::pair<int, int>> prerequisites{ {0, 1}, {0, 2}, {1, 2} };
    //std::cout<<s.canFinish(3, prerequisites)<<std::endl;
    //std::vector<std::pair<int, int>> prerequisites{ {0, 1}, {1, 0} };

    std::vector<std::pair<int, int>> prerequisites{ {1, 0} };
    auto v=s.findOrder(2, prerequisites);
    for(int n : v)
    {
        std::cout<<n<<" ";
    }
    std::cout<<std::endl;


    return 0;
}

