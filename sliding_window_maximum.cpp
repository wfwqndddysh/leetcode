#include<iostream>
#include<cassert>
#include<vector>
#include<climits>
#include<algorithm>
#include<map>
#include<deque>

class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        int sz=nums.size();
        if(sz==0) return {};

        std::vector<int> res;
        std::multimap<int, int> heap;

        for(int i=0; i<k; ++i)
        {
            heap.insert({nums[i], i});
        }

        auto cur_max=--heap.end();
        res.push_back(cur_max->first);

        for(int i=k; i<sz; ++i)
        {
            if(cur_max->second<=i-k)
            {
                heap.erase(cur_max);
                heap.insert({nums[i], i});
                cur_max=--heap.end();
                res.push_back(cur_max->first);
            }
            else
            {
                if(cur_max->first>nums[i])
                {
                    res.push_back(cur_max->first);
                }
                else
                {
                    res.push_back(nums[i]);
                }
                heap.erase(heap.find(nums[i-k]));
                heap.insert({nums[i], i});
                cur_max=--heap.end();
            }
        }

        return res;
    }
};

class SolutionDeque
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        int sz=nums.size();
        if(sz==0) return {};

        std::vector<int> res;
        std::deque<std::pair<int, int>> heap;
        heap.push_back({INT_MIN, -1});

        for(int i=0; i<k; ++i)
        {
            while(!heap.empty() && nums[i]>=heap.back().first)
                heap.pop_back();
            heap.push_back({nums[i], i});
        }

        res.push_back(heap.front().first);
        if(heap.front().second==0) heap.pop_front();

        for(int i=k; i<sz; ++i)
        {
            while(!heap.empty() && nums[i]>=heap.back().first)
                heap.pop_back();
            heap.push_back({nums[i], i});

            res.push_back(heap.front().first);
            if(i-heap.front().second==k-1) heap.pop_front();
        }

        return res;
    }
};

int main()
{
    //Solution s;
    SolutionDeque s;

    //std::vector<int> nums{1,3,-1,-3,5,3,6,7};
    //auto v=s.maxSlidingWindow(nums, 3);

    //std::vector<int> nums{1,-1};
    //auto v=s.maxSlidingWindow(nums, 1);

    std::vector<int> nums{1,3, 1, 2, 0, 5};
    auto v=s.maxSlidingWindow(nums, 3);

    for(int n : v)
        std::cout<<n<<' ';

    std::cout<<std::endl;
    return 0;
}

