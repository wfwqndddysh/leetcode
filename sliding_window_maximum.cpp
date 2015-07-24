#include<iostream>
#include<cassert>
#include<vector>
#include<climits>
#include<algorithm>

class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        int sz=nums.size();
        if(sz==0) return {};

        std::vector<int> res;
        std::vector<std::pair<int, int>> heap;

        for(int i=0; i<k; ++i)
        {
            heap.push_back({nums[i], i});
        }

        auto comp=[](const std::pair<int, int>& l, const std::pair<int, int>& r)
        {
            return l.first<r.first;
        };

        std::make_heap(heap.begin(), heap.end(), comp);
        res.push_back(heap.front().first);

        heap.push_back({nums[k], k});
        auto last=heap.size();

        for(int i=k; i<sz; ++i)
        {
            if(last==heap.size()) heap.resize(heap.size()+1);

            heap[last++]={nums[i], i};
            std::make_heap(heap.begin(), heap.begin()+last);

            while(heap[0].second<i-k)
            {
                std::pop_heap(heap.begin(), heap.begin()+last--);
            }

            res.push_back(heap[0].first);
        }

        return res;
    }
};

class Solution_
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        int sz=nums.size();
        if(sz==0) return {};

        std::vector<int> res;
        std::vector<std::pair<int, int>> heap;

        for(int i=0; i<k; ++i)
        {
            heap.push_back({nums[i], i});
        }

        auto comp=[](const std::pair<int, int>& l, const std::pair<int, int>& r)
        {
            return l.first<r.first;
        };
        std::make_heap(heap.begin(), heap.end(), comp);

        auto cur_max=heap[0];
        res.push_back(cur_max.first);

        for(int i=k; i<sz; ++i)
        {
            if(cur_max.second<=i-k)
            {
                std::pop_heap(heap.begin(), heap.end());
                heap.back()={nums[i], i};
                std::push_heap(heap.begin(), heap.end(), comp);
                cur_max=heap[0];
            }
            else
            {
                if(cur_max.first>nums[i])
                {
                }
                else
                {
                }
                cur_max=cur_max.first>nums[i] ? cur_max : std::pair<int, int>{nums[i], i};
                heap[0]=cur_max;
            }
            res.push_back(cur_max.first);
        }

        return res;
    }
};

int main()
{
    Solution_ s;

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
