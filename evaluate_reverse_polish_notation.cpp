#include<iostream>
#include<cassert>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<cassert>

class Solution
{
public:
    int evalRPN(std::vector<std::string>& tokens)
    {
        assert(tokens.size()>0);

        auto sz=tokens.size();
        std::stack<std::pair<bool, int>> expression;

        for(int i=sz-1; i>=0; --i)
        {
            if(be_sign(tokens[i]))
            {
                expression.push(std::make_pair(true, tokens[i][0]));
            }
            else
            {
                int a = std::stoi(tokens[i]);
                while(!expression.empty() && !expression.top().first)
                {
                    int b = expression.top().second;
                    expression.pop();
                    a = eval(a, b, expression.top().second);
                    expression.pop();
                }
                expression.push(std::make_pair(false, a));
            }
        }

        return expression.top().second;
    }

    bool be_sign(const std::string& s)
    {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }

    int eval(int a, int b, int sign)
    {
        switch(sign)
        {
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return a/b;
            default:
                std::cout<<"impossible to reach here"<<std::endl;
                return -1;
        }
    }

    int evalRPN_rec(std::vector<std::string>& tokens)
    {
        const std::string s = tokens.back();
        tokens.pop_back();
        if(be_sign(s))
        {
            int r2 = evalRPN_rec(tokens);
            int r1 = evalRPN_rec(tokens);
            return eval(r1, r2, s[0]);
        }
        else
        {
            return std::stoi(s);
        }
    }
};

int main()
{
    Solution s;
    //std::vector<std::string> tokens {"2", "1", "+", "3", "*"};
    //std::vector<std::string> tokens {"4", "13", "5", "/", "+"};
    std::vector<std::string> tokens {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};
    std::cout<<s.evalRPN_rec(tokens)<<std::endl;
    return 0;
}


