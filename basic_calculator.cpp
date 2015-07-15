#include<iostream>
#include<cassert>
#include<string>
#include<stack>

class Solution
{
public:
    int calculate(const std::string& s)
    {
        int len=s.length();
        if(len==0) return 0;

        int res=0;
        std::stack<int> st;

        int cur=0;
        bool be_prev_sign=false;
        for(; cur<len; )
        {
            while(s[cur]==' ' || s[cur]=='\t')
                cur++;

            if(cur==len) break;

            if(s[cur]=='(')
            {
                st.push('(');
                be_prev_sign=false;
                cur++;
            }
            else if(s[cur]==')')
            {
                cur++;

                int num2=st.top();
                st.pop();

                st.pop();//'('

                if(st.empty())
                {
                    st.push(num2);
                    continue;
                }

                char sign=st.top();//'+', '-'
                st.pop();

                int num1=st.top();
                st.pop();

                res=cal(num1, num2, sign);
                st.push(res);
            }
            else if(s[cur]>='0' && s[cur]<='9')
            {
                int n=0;
                while(s[cur]>='0' && s[cur]<='9')
                    n = n*10 + s[cur++]-'0';

                if(be_prev_sign)
                {
                    int sign=st.top();
                    st.pop();
                    res = cal(st.top(), n, sign);
                    st.pop();
                    st.push(res);
                }
                else
                {
                    st.push(n);
                }
            }
            else// +,-
            {
                st.push(s[cur]);
                be_prev_sign=true;
                cur++;
            }
        }

        return st.top();
    }

private:
    int cal(int a, int b, char c)
    {
        if(c=='+') return a+b;
        if(c=='-') return a-b;
        return 0;
    }
};

int main()
{
    Solution s;
    //std::cout<<s.calculate("1")<<std::endl;
    //std::cout<<s.calculate("(1)")<<std::endl;
    //std::cout<<s.calculate("(4+9)")<<std::endl;
    //std::cout<<s.calculate("1+1")<<std::endl;
    //std::cout<<s.calculate("1-(5)")<<std::endl;
    //std::cout<<s.calculate("5  ")<<std::endl;
    std::cout<<s.calculate("(3)+1")<<std::endl;
    return 0;
}

