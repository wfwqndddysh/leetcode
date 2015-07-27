#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int rob(std::vector<int>& nums)
    {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        return std::max(rob_internal(nums, 0, nums.size()-1), rob_internal(nums, 1, nums.size()));
    }

    int rob_internal(std::vector<int>& nums, int beg, int end)
    {
        int money = 0;
        int money_prev = 0;
        int money_prev_prev = 0;

        for(int i=beg; i<end; ++i)
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

