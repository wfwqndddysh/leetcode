#include<iostream>
#include<cassert>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        x=std::abs(x);
        int cnt=0;
        int num=x;

        while(num!=0)
        {
            num /= 10;
            cnt++;
        }

        num=x;
        while(num>10)
        {
            int high_single=num/(cnt*10);
            int low_single=num%10;

            if(high_single!=low_single)
                return false;

            int high=high_single;
            for(int i=0; i<cnt-1; ++i)
            {
                high = high*10;
            }

            num = num-high;
            num /= 10;
        }

        return true;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

