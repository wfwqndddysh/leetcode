#include<iostream>
#include<cassert>
#include<vector>
#include<climits>

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

class Solution_
{
public:
    int minSubArrayLen(int s, std::vector<int>& nums)
    {
        int min_len=0;
        int cur_sum=0;

        size_t start=0;
        bool found=false;
        for(size_t i=0; i<nums.size(); ++i)
        {
            cur_sum += nums[i];

            if(min_len==0 && cur_sum<s)
                continue;
            else if(min_len==0 && cur_sum>=s)
                min_len = i+1;

            if(cur_sum-nums[start]>=s)
            {
                for(min_len=found?min_len:min_len+1; cur_sum>=s && start<i; )
                {
                    min_len--;
                    cur_sum -= nums[start++];
                }
            }
            else if(cur_sum>=s)
            {
                if(found) min_len--;
                cur_sum = cur_sum - nums[start++];
            }
            cur_sum = cur_sum - nums[start++];

            found=true;
            if(min_len==1) break;
        }

        return min_len;
    }
};

class SolutionLeetCode
{
public:
    int minSubArrayLen(int s, std::vector<int>& nums)
    {
        int firstPos = 0, sum = 0, minLength = INT_MAX;
        
        for(int i = 0; i<(int)nums.size(); i++)
        {
            sum += nums[i];
            while(sum >= s)
            {
                minLength = std::min(minLength, i - firstPos + 1);
                sum -= nums[firstPos++];
            }
        }

        return minLength == INT_MAX? 0 : minLength;
    }
};

int main()
{
    Solution_ s;
    //std::vector<int> nums{1, 4, 4};
    //std::vector<int> nums{1, 2, 3, 4, 5};
    //std::vector<int> nums{5,1,3 ,5,10,7,4,9,2,8};
    //std::vector<int> nums{1,1,1,1,1,3,2};
    std::vector<int> nums{2,3,1,2,4,3};

    std::cout<<s.minSubArrayLen(7, nums)<<std::endl;
    return 0;
}

