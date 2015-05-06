#include<iostream>
#include<cassert>
#include<cmath>

class Solution
{
public:
    int count_primes(int n)
    {
        assert(n>=2);
        int count_of_primes = 0;
        for(int i=2; i<n; i++)
        {
            int s_root = static_cast<int>(sqrt(i));
            for(int j=2; j<=s_root; ++j)
            {
                if((i%j) == 0)
                {
                    goto next_num;
                }
            }
            ++count_of_primes;
next_num:
            continue;
        }
        return count_of_primes;
    }
};

int main()
{
    Solution s;
    int n = 1500000;
    std::cout<<"count: "<<s.count_primes(n)<<std::endl;
    return 0;
}

