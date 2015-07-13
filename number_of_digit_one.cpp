#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int countDigitOne(int n)
    {
        if(n<1) return 0;
        if(n<9) return 1;

        int res=0;
        std::vector<int> table(12, 1);

        int m=n%10;
        int tn=n/10;
        int low=m;
        res=m>0 ? 1 : 0;

        for(int i=2, base=1; tn!=0; i++, tn /= 10)
        {
            base = base*10;
            table[i]=10*table[i-1]+base;

            m=tn%10;

            if(m!=0)
            {
                res += m*table[i-1] + std::min(m*base+low-base+1, base);
            }

            low = m*base+low;
        }

        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.countDigitOne(13)<<std::endl;
    std::cout<<s.countDigitOne(100)<<std::endl;
    std::cout<<s.countDigitOne(20)<<std::endl;
    return 0;
}

