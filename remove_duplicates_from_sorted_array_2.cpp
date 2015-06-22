#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        auto sz = nums.size();
        if(sz<3) return sz;

        int len = 2;
        for(size_t i=2; i<nums.size(); ++i)
        {
            if(!(nums[i]==nums[len-1] && nums[len-1]==nums[len-2]))
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
    //std::vector<int> nums(2, 1);
    //std::vector<int> nums{1, 1, 1, 2, 2, 3};
    //std::vector<int> nums{1, 2, 2};
    std::vector<int> nums{1, 1, 1};
    std::cout<<s.removeDuplicates(nums)<<std::endl;
    return 0;
}

