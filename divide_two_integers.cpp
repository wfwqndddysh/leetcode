#include<iostream>
#include<cassert>
#include<climits>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if(divisor==0) return INT_MAX;
        if(dividend==0) return 0;

        bool negative=false;
        if(dividend<0) negative=!negative;
        if(divisor<0) negative=!negative;

        int64_t d1=std::abs((int64_t)dividend);
        int64_t d2=std::abs((int64_t)divisor);
        int64_t cur=d2;

        int64_t ret=0;

        while(d1>=d2)
        {
            int64_t cnt = 1;
            while(d1-cur>=cur)
            {
                cnt+=cnt;
                cur+=cur;
            }
            ret += cnt;
            d1=d1-cur;
            cur=d2;
        }

        if(ret-1==INT_MAX && !negative) return INT_MAX;

        return negative ? -ret : ret;
    }
};

class SolutionLeetCode
{
public:
    int divide(int dividend, int divisor)
    {
        int sign = 1;
        if (dividend<0){sign = -sign;}
        if (divisor<0){sign = -sign;}

        unsigned long long tmp = std::abs((long long)dividend);
        unsigned long long tmp2 = std::abs((long long)divisor);

        unsigned long c = 1;
        while (tmp>tmp2){
            tmp2 = tmp2<<1;
            c = c<<1;
        }

        int res = 0;
        while (tmp>=std::abs((long long)divisor))
        {
            while (tmp>=tmp2){
                tmp -= tmp2;
                res = res+c;
            }
            tmp2=tmp2>>1;
            c=c>>1;
        }

        return sign*res;
    }
};


int main()
{
    Solution s;
    //std::cout<<s.divide(2147483647, 1)<<std::endl;
    //std::cout<<s.divide(-1010369383, -2147483648)<<std::endl;
    //std::cout<<s.divide(-2147483648, -1)<<std::endl;
    std::cout<<s.divide(-2147483648, 1)<<std::endl;
    return 0;
}

