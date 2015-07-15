#include<iostream>
#include<cassert>
#include<string>
#include<stack>

class Solution
{
public:
    int calculate(const std::string& s)
    {
        size_t len=s.length();

        int sign=1;
        size_t i=0;
        int sum=get_product(s, i, sign);

        for(; i<len; )
        {
            int as_sign=sign;
            int num=get_product(s, i, sign);
            sum = as_sign=='+' ? sum+num : sum-num;
        }

        return sum;
    }

private:
    int get_product(const std::string& s, size_t& i, int& sign)
    {
        int product=get_num(s, i);
        for(; i<s.length(); )
        {
            if(s[i]=='+' || s[i]=='-')
            {
                sign=s[i++];
                break;
            }

            int md_sign=s[i++];
            int num=get_num(s, i);
            product=md_sign=='*' ? product*num : product/num;
        }
        return product;
    }

    int get_num(const std::string& s, size_t& i)
    {
        int n=0;
        for(; i<s.length(); ++i)
        {
            if(s[i]==' ' || s[i]=='\t')
                continue;
            if(s[i]>='0' && s[i]<='9')
                n = n*10 + s[i]-'0';
            else
            {
                break;
            }
        }
        return n;
    }
};

int main()
{
    Solution s;
    //std::cout<<s.calculate("2*3+4")<<std::endl;
    //std::cout<<s.calculate("1+1+1")<<std::endl;
    std::cout<<s.calculate("1+1-1")<<std::endl;
    return 0;
}

