#include<iostream>
#include<cassert>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

class Solution
{
public:
    int longestValidParentheses(std::string s)
    {
        int sz=s.size();
        if(sz==0) return 0;

        int longest=0;
        int new_longest=0;
        std::vector<std::pair<int, int>> ranges;
        std::stack<std::pair<char, int>> st;

        for(int i=0; i<sz; ++i)
        {
            if(s[i]==')')
            {
                if(!st.empty())
                {
                    ranges.push_back({st.top().second, i});
                    st.pop();
                }
            }
            else
            {
                st.push({s[i], i});
            }
        }

        auto comp=[](const std::pair<int, int>& l, const std::pair<int, int>& r)
            { return l.first<r.first; };

        std::sort(ranges.begin(), ranges.end(), comp);

        //合并range
        if(ranges.size()>0) longest=new_longest=ranges[0].second-ranges[0].first+1;
        int prev=0;
        for(size_t i=1; i<ranges.size(); ++i)
        {
            if(ranges[prev].second+1==ranges[i].first)
            {
                new_longest += ranges[i].second-ranges[i].first+1;
                prev=i;
            }
            else if(ranges[prev].second+1<ranges[i].first)
            {
                longest = std::max(longest, new_longest);
                new_longest = ranges[i].second-ranges[i].first+1;
                prev=i;
            }
        }

        return std::max(longest, new_longest);
    }
};

class Solution_
{
public:
    int longestValidParentheses(std::string s)
    {
        int sz=s.size();
        if(sz==0) return 0;

        int longest=0;
        int continuous_len=0;
        std::stack<std::pair<int, int>> ranges;
        std::stack<std::pair<char, int>> st;
        std::pair<int, int> cur_range;
        for(int i=0; i<sz; ++i)
        {
            if(s[i]==')')
            {
                if(!st.empty())//找到一个new range
                {
                    cur_range = {st.top().second, i};
                    continuous_len = cur_range.second-cur_range.first+1;
                    longest=std::max(longest, continuous_len);

                    for(;!ranges.empty();)
                    {
                        if(cur_range.first<ranges.top().first)
                        {
                            longest = std::max(longest , continuous_len);
                            ranges.pop();
                        }
                        else if(ranges.top().second+1==cur_range.first)
                        {
                            continuous_len += ranges.top().second-ranges.top().first+1;
                            cur_range = {ranges.top().first, cur_range.second};
                            longest = std::max(longest , continuous_len);
                        }
                        else
                        {
                            break;
                        }
                    }
                    ranges.push(cur_range);
                    st.pop();
                }
            }
            else
            {
                st.push({s[i], i});
            }
        }

        return longest;
    }
};

int main()
{
    Solution_ s;
    //std::string parentheses("()(()");
    //std::string parentheses("()");
    //std::string parentheses("()()");
    //std::string parentheses("())");
    //std::string parentheses(")(");
    //std::string parentheses("()()");
    //std::string parentheses("(()");
    //std::string parentheses(")()())()()(");
    //std::string parentheses("()(())");
    std::string parentheses("(()()(())((");
    std::cout<<s.longestValidParentheses(parentheses)<<std::endl;
    return 0;
}

