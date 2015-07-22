#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int minSubArrayLen(int s, std::vector<int>& nums)
    {
        int min_len=0;
        int cur_sum=0;

        size_t start=0;
        size_t i=0;
        for(; i<nums.size(); ++i)
        {
            cur_sum+=nums[i];
            if(cur_sum>=s)
            {
                for(min_len=i+1; cur_sum-nums[start]>=s && start<i; )
                {
                    min_len--;
                    cur_sum -= nums[start++];
                }
                break;
            }
        }

        if(min_len<2) return min_len;

        cur_sum = cur_sum-nums[start]-nums[start+1];
        start +=2;

        for(i++; i<nums.size(); ++i)
        {
            if(nums[i]>=s) return 1;
            cur_sum += nums[i];

            if(cur_sum-nums[start]>=s)
            {
                for(; cur_sum>=s && start<i; )
                {
                    min_len--;
                    cur_sum -= nums[start++];
                }
                cur_sum -= nums[start++];
            }
            else if(cur_sum>=s)
            {
                min_len--;
                cur_sum = cur_sum - nums[start++];
                cur_sum = cur_sum - nums[start++];
            }
            else
            {
                cur_sum = cur_sum - nums[start++];
            }

            if(min_len==1) break;
        }

        return min_len;
    }
};

int main()
{
    Solution s;
    //std::vector<int> nums{1, 4, 4};
    //std::vector<int> nums{1, 2, 3, 4, 5};
    //std::vector<int> nums{5,1,3 ,5,10,7,4,9,2,8};

    std::vector<int> nums{1,1,1,1,1,3,2};
    std::cout<<s.minSubArrayLen(5, nums)<<std::endl;
    return 0;
}

