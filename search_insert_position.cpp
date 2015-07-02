#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        size_t index=0;

        for(; index<nums.size(); ++index)
        {
            if(target<=nums[index])
                return index;
        }

        return index;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

