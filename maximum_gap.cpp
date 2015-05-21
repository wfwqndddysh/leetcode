#include<iostream>
#include<cassert>
#include<vector>
#include<climits>

class Solution
{
public:
    int maximumGap(const std::vector<int>& nums)
    {
        auto sz = nums.size();
        if(sz<2) return 0;

        //get global max, min
        int g_max = nums[0];
        int g_min = nums[0];
        for(auto x : nums)
        {
            if(x < g_min)
                g_min = x;
            else if(x > g_max)
                g_max = x;
        }

        //get num of buckets
        size_t buckets_len = (g_max-g_min)/sz+1;
        size_t buckets_num = (g_max-g_min)/buckets_len+1;
        std::vector<std::vector<int>> buckets(buckets_num);

        for(int x : nums)
        {
            int loc = (x-g_min)/buckets_len;
            if(buckets[loc].empty())
            {
                //more effective
                buckets[loc].reserve(2);
                buckets[loc].push_back(x);
                buckets[loc].push_back(x);
            }
            else
            {
                buckets[loc][0] = std::min(buckets[loc][0], x);
                buckets[loc][1] = std::max(buckets[loc][1], x);
            }
        }

        int max_gap = 0;
        for(size_t i=0, prev=0; i<buckets.size(); ++i)
        {
            if(buckets[i].empty()) continue;
            max_gap = std::max(max_gap, buckets[i][0]-buckets[prev][1]);
            prev = i;
        }
        return max_gap;
    }

    int maximumGap_sort(const std::vector<int>& nums)
    {
        return 0;
    }

    void radix_sort(std::vector<int>& nums)
    {
    }

    void count_sort(std::vector<int>& nums)
    {
        //std::vector<int> 
    }
};

int main()
{
    Solution s;
    std::cout<<s.maximumGap({1,10000000})<<std::endl;
    return 0;
}

