#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
#include<climits>

class Solution
{
public:
    void nextPermutation(std::vector<int>& nums)
    {
        int n=nums.size();
        if(n<2) return;

        int j=n-2;
        for(; j>=0; --j)
        {
            if(nums[j]<nums[j+1]) break;
        }

        if(j==-1)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int min_i=-1;
        int min = INT_MAX;
        for(int m=n-1; m>j; --m)
        {
            if(nums[m]>nums[j] && nums[m]<min)
            {
                min_i = m;
                min = nums[m];
            }
        }

        std::swap(nums[j], nums[min_i]);
        std::reverse(nums.begin()+j+1, nums.end());
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{16,27,25,23,25,16,12,9,1,2,7,20,19,23,16,0,6,22,16,11,8,27,9,2,20,2,13,7,25,29,12,12,18,29,27,13,16,1,22,9,3,21,29,14,7,8,14,5,0,23,16,1,20};
    s.nextPermutation(nums);
    std::cout<<std::endl;
    return 0;
}

