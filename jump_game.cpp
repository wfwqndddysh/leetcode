#include<iostream>
#include<cassert>
#include<vector>

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
*/

class Solution
{
public:
    bool canJump(std::vector<int>& nums)
    {
        int sz=nums.size();
        if(sz<2) return true;
        int most_far = -1;
        for(int i=0; i<sz-1; ++i)
        {
            most_far = std::max(most_far, nums[i]+i);
            if(most_far<=i) return false;
            if(most_far>=sz-1) return true;
        }
        return true;
    }
};

class SolutionMySecond
{
public:
    bool canJump(vector<int>& nums)
    {
        int curr_max = 0;
        int i=0;
        for(; i<nums.size(); ++i)
        {
            if(curr_max>i)
            {
                curr_max = std::max(curr_max, nums[i]+i);
            }
            else if(curr_max==i)
            {
                curr_max = nums[i]+i;
            }

            if(curr_max<i) break;
        }

        return i==nums.size();
    }
};
int main()
{
    Solution s;
    //std::vector<int> nums{0, 1};
    std::vector<int> nums{2, 0, 0};
    std::cout<<s.canJump(nums)<<std::endl;
    return 0;
}
