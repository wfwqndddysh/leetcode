#include<iostream>
#include<cassert>
#include<vector>

/*
You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed, the only constraint stopping you from
robbing each of them is that adjacent houses have security system connected and
it will automatically contact the police if two adjacent houses were broken
into on the same night.

Given a list of non-negative integers representing the amount of money of each
house, determine the maximum amount of money you can rob tonight without
alerting the police.
*/

class Solution
{
public:
    int robRec(std::vector<int>& nums)
    {
        return rob_internal(nums, 0);
    }

    int rob_internal(const std::vector<int>& nums, size_t index)
    {
        if(nums.size()<(index+1))
            return 0;

        int a = nums[index] + rob_internal(nums, index+2);
        int b = rob_internal(nums, index+1);

        return a > b ? a : b;
    }

    int rob(std::vector<int>& nums)
    {
        int money = 0;
        int money_prev = 0;
        int money_prev_prev = 0;

        for(size_t i=0; i<nums.size(); ++i)
        {
            money = money_prev_prev + nums[i];
            money = money > money_prev ? money : money_prev;
            money_prev_prev = money_prev;
            money_prev = money;
        }
        return money;
    }
};

int main()
{
    Solution s;
    std::vector<int> houses {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    std::cout<<s.rob(houses)<<std::endl;
    return 0;
}

