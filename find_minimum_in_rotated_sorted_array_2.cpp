#include<iostream>
#include<cassert>
#include<vector>
#include<climits>

class Solution
{
public:
    int findMin(const std::vector<int>& nums)
    {
        auto sz = nums.size();
        if(sz==0) return INT_MIN;
        return find_rec(nums, 0, sz-1);
    }

    int find_rec(const std::vector<int>& nums, int beg, int end)
    {
        int mid = 0;
        while(beg<=end)
        {
            mid = beg + (end-beg)/2;
            if(beg==end)
            {
                return nums[beg];
            }
            else if(beg+1==end)
            {
                return std::min(nums[beg], nums[end]);
            }
            else if(nums[mid]>nums[end])
            {
                beg = mid;
            }
            else if(nums[mid]<nums[end])
            {
                end = mid;
            }
            else//==
            {
                int left_min = find_rec(nums, beg, mid);
                if(left_min<nums[mid])
                    return left_min;

                beg = mid;
            }
        }
        return nums[mid];
    }

    int findMin_leetcode(const std::vector<int> &num)
    {
        int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;

        while(lo < hi)
        {
            mid = lo + (hi - lo) / 2;

            if (num[mid] > num[hi])
            {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi])
            {
                hi = mid;
            }
            else // when num[mid] and num[hi] are same
            {
                hi--;
            }
        }
        return num[lo];
    }
};

int main()
{
    Solution s;
    std::cout<<s.findMin({3, 3, 1, 3})<<std::endl;
    return 0;
}

