#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        int cur = -1;
        for(size_t i=0; i<nums.size(); ++i)
        {
            if(nums[i]!=val)
                nums[++cur]=nums[i];
        }

        return cur+1;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

