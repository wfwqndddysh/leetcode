#include<iostream>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
#include<stack>
#include<list>

class Solution
{
public:
    std::vector<std::string> wordBreak(std::string s, const std::unordered_set<std::string> &dict)
    {
        size_t len = s.length();
        std::vector<std::string> sentences;
        std::vector<std::pair<size_t, size_t>> dfs;
        std::vector<bool> visited(len, false);
        size_t group_index = 0;

        std::vector<std::vector<std::list<size_t>>> paths(len);
        std::list<std::pair<size_t, size_t>> cur_pop_list;

        dfs.push_back({0, 0});
        while(!dfs.empty())
        {
            auto start = dfs.back();
            dfs.pop_back();
            cur_pop_list.push_back(start);

            //if(!visited[start])
            {
                visited[start.second]=true;
                size_t cnt = 0;
                size_t cur_g_i = group_index+1;
                for(size_t i=start.second; i<len; ++i)
                {
                    if(dict.count(s.substr(start.second, i-start.second+1))>0)
                    {
                        dfs.push_back({cur_g_i, i+1});
                        cnt++;
                        if(i+1==len)
                        {
                            //paths[start.second].push_back(std::list<std::size_t>(1, start.second));
                            for(auto n : cur_pop_list)
                            {
                                std::cout<<n.second<<" ";
                                paths[0].push_back(cur_pop_list);
                            }
                            std::cout<<std::endl;
                        }
                    }
                }
                group_index = cur_g_i > group_index? cur_g_i : group_index;
                if(cnt==0)
                {
                    while(!cur_pop_list.empty() && cur_pop_list.back().first>=dfs.back().first)
                        cur_pop_list.pop_back();
                }
            }
            /*
            else
            {
                auto index = dfs.back();
                for(size_t i_paths=0; i_paths<paths[start].size(); ++i_paths)
                {
                    paths[index].push_back(paths[start][i_paths]);
                    paths[index].back().push_front(index);
                }
            }
            */
        }

        /*
        int first_non_0 = -1;
        for(size_t i=0; i<len; ++i)
        {
            if(paths[i].size()>0)
            {
                first_non_0 = i;
                break;
            }
        }
        if(first_non_0<0)
            return sentences;

        const auto& vl = paths[first_non_0];
        for(size_t i=0; i<vl.size(); ++i)
        {
            std::string sentence;
            for(auto itr=vl[i].cbegin(); itr!=vl[i].cend(); )
            {
                if(itr==vl[i].cbegin())
                {
                    sentence += s.substr(0, *itr);
                    sentence += " ";
                    itr++;
                }
                else
                {
                    auto ti = itr++;
                    sentence += s.substr(*ti, *itr-*ti);
                    sentence += " ";
                }
            }
            sentence += s.substr(vl[i].back());
            sentences.push_back(sentence);
        }
        */
        return sentences;
    }
};

int main()
{
    Solution s;
    //std::cout<<s.wordBreak("a", std::unordered_set<std::string>())<<std::endl;
    //auto ss="leetcode";
    //std::unordered_set<std::string> m{"leet", "code"};

    //auto ss="ab";
    //std::unordered_set<std::string> m{"a", "b"};

    auto ss="catsanddog";
    std::unordered_set<std::string> m{"cat", "cats", "and", "sand", "dog"};

    std::vector<std::string> ret = s.wordBreak(ss, m);
    for(const auto& s : ret)
    {
        std::cout<<s<<std::endl;
    }
    return 0;
}

