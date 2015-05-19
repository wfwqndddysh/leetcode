#include<iostream>
#include<cassert>
#include<climits>

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int cnt = 0;
        while(n>=5)
        {
            n = n/5;
            cnt += n;
        }
        return cnt;
    }

    int trailingZeroes_mutl(int n)
    {
        int cnt = 0;
        long long five_multi = 5;
        while(five_multi<=(long long)n)
        {
            cnt += n / five_multi;
            five_multi *= 5;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    //std::cout<<s.trailingZeroes(5)<<std::endl;
    std::cout<<s.trailingZeroes_mutl(1808548329)<<std::endl;
    return 0;
}

