#include<iostream>
#include<cassert>
#include<string>
#include<stack>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<int> parentheses;
        std::stack<int> brackets;
        std::stack<int> braces;

        for(size_t i=0; i<s.size(); ++i)
        {
            if(s[i]=='(')
            {
                parentheses.push(i);
            }
            else if(s[i]=='[')
            {
                brackets.push(i);
            }
            else if(s[i]=='{')
            {
                braces.push(i);
            }
            else if(s[i]==')')
            {
                if(parentheses.empty()) return false;
                if(!brackets.empty() && brackets.top()>parentheses.top()) return false;
                if(!braces.empty() && braces.top()>parentheses.top()) return false;
                parentheses.pop();
            }
            else if(s[i]==']')
            {
                if(brackets.empty()) return false;
                if(!parentheses.empty() && parentheses.top()>brackets.top()) return false;
                if(!braces.empty() && braces.top()>brackets.top()) return false;
                brackets.pop();
            }
            else if(s[i]=='}')
            {
                if(braces.empty()) return false;
                if(!parentheses.empty() && parentheses.top()>braces.top()) return false;
                if(!brackets.empty() && brackets.top()>braces.top()) return false;
                braces.pop();
            }
        }

        return parentheses.empty() && brackets.empty() && braces.empty();
    }
};

class SolutionLeetCode
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> opens;
        for(size_t i=0; i<s.size(); ++i)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                opens.push(s[i]);
            else if(s[i]==')' && !opens.empty() && opens.top()=='(')
                opens.pop();
            else if(s[i]==']' && !opens.empty() && opens.top()=='[')
                opens.pop();
            else if(s[i]=='}' && !opens.empty() && opens.top()=='{')
                opens.pop();
            else 
                return false;
        }

        return opens.empty();
    }
};

int main()
{
    Solution s;
    //std::string str("()");
    std::string str("()[]{}");
    std::cout<<s.isValid(str)<<std::endl;
    return 0;
}

