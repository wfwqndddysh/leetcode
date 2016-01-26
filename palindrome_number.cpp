#include<iostream>
#include<cassert>
#include<climits>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x<0) return false;

        x=std::abs(x);
        int cnt=0;
        int num=x;

        while(num!=0)
        {
            num /= 10;
            cnt++;
        }

        num=x;
        //while(num>=10)

        for(; num>=10 || cnt>=2; cnt-=2)
        {
            int high=1;
            for(int i=0; i<cnt-1; ++i)
            {
                high = high*10;
            }

            int high_single=num/high;
            int low_single=num%10;

            if(high_single!=low_single)
                return false;

            num = num-high*high_single;
            num /= 10;
        }

        return true;
    }
};

//对于溢出应该是没有处理好的
class SolutionLeetCode
{
public:
    bool isPalindrome(int x)
    {
        if(x<0 || (x!=0 && x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};

class SolutionCleanCode
{
public:
    bool isPalindrome(int x)
    {
        if(x<0) return false;

        int div = 10;

        while(x / div >= 10)
        {
            div *= 10;
        }

        while( x != 0 )
        {
            int l = x / div;
            int r = x % 10;
            
            if(l != r) return false;

            x = ( x % div ) / 10;
            div /= 100;
        }

        return true;
    }
};


int main()
{
    Solution s;
    //std::cout<<s.isPalindrome(-10)<<std::endl;
    std::cout<<s.isPalindrome(1000021)<<std::endl;
    return 0;
}

