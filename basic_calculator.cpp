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

class SolutionLeetCode
{
public:
    int calculate(const std::string& s)
    {
        // the given expression is always valid!!!
        // only + and - !!!
        // every + and - can be flipped base on it's depth in ().
        std::stack<int> signs;
        int sign = 1;
        int num = 0;
        int ans = 0;

        // always transform s into ( s )
        signs.push(1);

        for (auto c : s)
        {
            if (c >= '0' && c <= '9')
            {
                num = 10 * num + c - '0';
            }
            else if (c == '+' || c == '-')
            {
                ans = ans + signs.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            }
            else if (c == '(')
            {
                signs.push(sign * signs.top());
                sign = 1;
            }
            else if (c == ')')
            {
                ans = ans + signs.top() * sign * num;
                num = 0;
                signs.pop();
                sign = 1;
            }
        }

        if (num)
        {
            ans = ans + signs.top() * sign * num;
        }

        return ans;
    }
};

/*
Thanks for chuang's answer. Make a version which is easy to understand.
Example: 7 - ( 6 - 5 - ( 4 - 3 ) - 2 ) - ( 1 )
Result: + 7 - 6 + 5 + 4 - 3 + 2 - 1
The bold + - are signs just before '('. They are dealt with previous stack sign. They are saved in the stack to help decide the signs in the following parentheses
*/

class SolutionLeetCode2
{
public:
    int calculate(std::string& s)
    {
        std::stack<int> t;  //previous sign just before the '('
        t.push(1);  //for all the signs those are not in the parentheses
        int sum=0, temp=0, lastSign=1;
        for(auto c: s)
        {
            if(c=='(')
            {
                t.push(lastSign); //save the sign just before the '('
            }
            else if(c==')')
            {
                t.pop();
            }

            if(c>='0' && c<='9')
            {
                temp=temp*10+c-'0';
            }

            if(c=='-'||c=='+')
            {
                sum+=lastSign*temp; //calculate the number before current sign
                temp=0;
                lastSign=(c=='-'?-1:1)*t.top();  //deal with the stack influencing sign
            }
        }
        sum+=lastSign*temp; //calculate the last number
        return sum;
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

