#include<iostream>
#include<cassert>
#include<vector>
#include<climits>

class Solution
{
public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        return rec(nums, 0, nums.size()-1, k);
    }

private:
    int rec(std::vector<int>& nums, int beg, int end, int k)
    {
        if(beg==end) return nums[beg];

        int mid=partition(nums, beg, end);

        if(mid-beg==k-1)
        {
            return nums[mid];
        }
        else if(mid-beg>k-1)
        {
            return rec(nums, beg, mid-1, k);
        }
        else
        {
            return rec(nums, mid+1, end, k-(mid-beg+1));
        }
    }

    int partition(std::vector<int>& nums, int beg, int end)
    {
        int pivot=nums[end];
        int cur=beg-1;
        for(int i=beg; i<end; ++i)
        {
            if(nums[i]>=pivot)
            {
                cur++;
                std::swap(nums[cur], nums[i]);
            }
        }
        std::swap(nums[cur+1], nums[end]);

        return cur+1;
    }
};

class SolutionLeetCode
{
public:
    int partition(std::vector<int>& nums, int left, int right)
    {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r)
        {
            if (nums[l] < pivot && nums[r] > pivot)
                std::swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        std::swap(nums[left], nums[r]);
        return r;
    }

    int findKthLargest(std::vector<int>& nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        while (true)
        {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};

int main()
{
    Solution s;

    //std::vector<int> nums{2, 1};
    //std::cout<<s.findKthLargest(nums, 1)<<std::endl;

    //std::vector<int> nums{-1, 2, 0};
    //std::cout<<s.findKthLargest(nums, 2)<<std::endl;

    //std::vector<int> nums{99, 99};
    //std::cout<<s.findKthLargest(nums, 1)<<std::endl;

    //std::vector<int> nums{3,3,3,3,3,3,3,3,3};
    //std::cout<<s.findKthLargest(nums, 8)<<std::endl;

    //std::vector<int> nums{3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    //std::cout<<s.findKthLargest(nums, 20)<<std::endl;

    std::vector<int> nums{3, 1, 2, 4};
    std::cout<<s.findKthLargest(nums, 2)<<std::endl;
    return 0;
}

