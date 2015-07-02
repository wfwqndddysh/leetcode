#include<iostream>
#include<cassert>
#include<string>
#include<stack>

class Solution
{
public:
    int longestValidParentheses(std::string s)
    {
        int sz=s.size();
        if(sz==0) return 0;

        int cur=0;
        int longest=0;

        int beg=-1;
        int end=-1;

        std::stack<std::pair<char, int>> st;
        st.push({s[sz-1], sz-1});

        for(int i=sz-2; i>=0; --i)
        {
            if(s[i]=='(')
            {
                if(!st.empty())
                {
                    cur_end=st.top().second;
                    st.pop();
                    if()
                    {
                    }
                    cur+=2;
                }
                else
                {
                    longest=std::max(longest, cur);
                    cur=0;
                }
            }
            else
            {
                st.push({s[i], i});
            }
        }

        return std::max(cur, longest);
    }
};

int main()
{
    Solution s;
    //std::string parentheses("()(()");
    //std::string parentheses("()");
    //std::string parentheses("()()");
    //std::string parentheses("()()");
    //std::string parentheses("(()");
    std::string parentheses(")()())()()(");
    std::cout<<s.longestValidParentheses(parentheses)<<std::endl;
    return 0;
}

