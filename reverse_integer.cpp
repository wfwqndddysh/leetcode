#include<iostream>
#include<cassert>
#include<climits>

class Solution
{
public:
    int reverse(int x)
    {
        int64_t res=0;

        while(x!=0)
        {
            res = res*10 + x%10;
            x /= 10;
        }

        return (res>INT_MAX || res<INT_MIN) ? 0 : res;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

