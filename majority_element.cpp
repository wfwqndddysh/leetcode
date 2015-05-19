#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int majorityElement(std::vector<int>& nums)
    {
        auto sz=nums.size();
        assert(sz>0);

        int candidate = nums[0];
        size_t cnt = 0;
        size_t index = 0;
        for(; index<sz-1; index+=2)
        {
            if(nums[index]!=nums[index+1])
                continue;

            if(cnt==0)
            {
                candidate = nums[index];
                ++cnt;
            }
            else
            {
                if(candidate==nums[index])
                {
                    ++cnt;
                }
                else
                {
                    --cnt;
                }
            }
        }
        
        //odd
        if(index<sz && cnt==0)
        {
            candidate = nums[index];
        }

        return candidate;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}


