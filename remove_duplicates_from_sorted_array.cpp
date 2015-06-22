#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        if(nums.size()==0) return 0;

        int len = 1;
        for(size_t i=1; i<nums.size(); ++i)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[len]=nums[i];
                len++;
            }
        }
        return len;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

