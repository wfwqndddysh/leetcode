#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        int d=1;

        for(int i=digits.size()-1; i>=0; --i)
        {
            int sum=digits[i]+d;

            if(sum>=10)
            {
                digits[i]=sum-10;
                d=1;
            }
            else
            {
                digits[i]=sum;
                d=0;
            }
        }

        if(d==1) digits.insert(digits.cbegin(), 1);

        return digits;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

