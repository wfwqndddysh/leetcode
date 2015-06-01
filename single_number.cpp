#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int singleNumber(const std::vector<int>& nums)
    {
        assert(nums.size()>0);
        int ret = 0;
        for(int n : nums)
            ret ^= n;
        return ret;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

