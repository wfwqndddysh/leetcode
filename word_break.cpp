#include<iostream>
#include<cassert>
#include<unordered_set>
#include<string>
#include<vector>
#include<queue>

//有几点值得我们学习
/*
1.从头开始，从长度1开始，不用计算所有长度为1的
2.转化为图的问题，这个很赞
3.优化，从后往前，计算有效长度很赞
*/
class Solution
{
public:
    bool wordBreak(std::string s, const std::unordered_set<std::string>& wordDict)
    {
        auto s_len=s.length();
        std::unordered_set<std::string> dp;
        for(size_t len=1; len<=s.length(); ++len)
        {
            for(size_t i=0; i<=s_len-len; ++i)
            {
                const std::string& ss=s.substr(i, len);

                if(wordDict.count(ss)>0)
                {
                    dp.insert(ss);
                }
                else
                {
                    auto ss_len = ss.length();
                    for(size_t l=1; l<ss_len; ++l)
                    {
                        const std::string& left = ss.substr(0, l);
                        const std::string& right = ss.substr(l, ss_len-l);
                        if(dp.count(left)>0 && dp.count(right)>0)
                        {
                            dp.insert(ss);
                            break;
                        }
                    }
                }
            }
        }
        return dp.count(s)>0;
    }

    bool wordBreak_rec(const std::string& s, const std::unordered_set<std::string>& wordDict)
    {
        auto s_len=s.length();
        if(wordDict.count(s)>0) return true;
        for(size_t len=1; len<s_len; ++len)
        {
            if(wordBreak(s.substr(0, len), wordDict) && wordBreak(s.substr(0+len, s_len-len), wordDict))
                return true;
        }
        return false;
    }

    bool wordBreakLeetCode(std::string s, const std::unordered_set<std::string>& dict)
    {
        std::vector<bool> flag(s.size()+1, false);
        flag[0] = true;

        /*
        for(size_t  i=1; i<=s.length(); i++)
        {
            for(const auto& str: dict)
            {
                auto len = str.length();
                if(len <= i)
                {
                    if(flag[i-len])
                    {
                        if(s.substr(i-len, len)==str)
                        {
                            flag[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        */

        //Second DP
        for(size_t i=1; i <= s.length(); i++)
        {
            for(size_t j=0; j < i; j++)
            {
                if(flag[j] && dict.count(s.substr(j, i-j))>0)
                {
                    flag[i] = true;
                    break;
                }
            }
        }

        return flag[s.length()];
    }

    bool wordBreakBFS(std::string s, const std::unordered_set<std::string> &dict)
    {
        // BFS
        using namespace std;
        queue<int> BFS;
        unordered_set<int> visited;

        BFS.push(0);
        while(BFS.size() > 0)
        {
            int start = BFS.front();
            BFS.pop();
            if(visited.find(start) == visited.end())
            {
                visited.insert(start);
                for(size_t j=start; j<s.size(); j++)
                {
                    string word(s, start, j-start+1);
                    if(dict.find(word) != dict.end())
                    {
                        BFS.push(j+1);
                        if(j+1 == s.size())
                            return true;
                    }
                }
            }
        }

        return false;
    }

    bool wordBreak0ms(std::string s, std::unordered_set<std::string> &dict)
    {
        if (dict.empty())
            return false;
        size_t len = s.size(), max_len = dict.begin()->size(), min_len = max_len;
        for (auto it = dict.begin(); it != dict.end(); ++it)
            if (it->size() > max_len)
                max_len = it->size();
            else if (it->size() < min_len)
                min_len = it->size();
        std::vector<int> flag(len + 1);
        flag[len] = 1;
        for (int i = len - 1; i >= 0; --i)
            for (int j = min_len; j <= std::min(max_len, len - i); ++j)
                if (flag[i + j] && dict.find(s.substr(i, j)) != dict.end()) {
                    flag[i] = 1;
                    break;
                }
        return flag[0] == 1;
    }
};

int main()
{
    Solution s;
    //std::cout<<s.wordBreak("a", std::unordered_set<std::string>())<<std::endl;
    //auto ss="leetcode";
    //std::unordered_set<std::string> m{"leet", "code"};

    auto ss="a";
    std::unordered_set<std::string> m{"a"};
    std::cout<<s.wordBreak(ss, m)<<std::endl;
    return 0;
}

