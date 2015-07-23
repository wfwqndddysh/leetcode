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

int main()
{
    Solution s;
    std::vector<int> nums{1,3,-1,-3,5,3,6,7};
    auto v=s.maxSlidingWindow(nums, 3);

    for(int n : v)
        std::cout<<n<<' ';

    std::cout<<std::endl;
    return 0;
}

