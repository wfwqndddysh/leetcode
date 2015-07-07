#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
#include<unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<std::pair<int, int>> cp;

        for(int i=0; i<(int)nums.size(); ++i)
        {
            cp.push_back({nums[i], i});
        }

        auto comp=[](const std::pair<int, int>& l, const std::pair<int, int>& r)
            { return l.first<r.first;};

        std::sort(cp.begin(), cp.end(), comp);
        std::vector<int> res;
        for(int i=0; i<(int)cp.size()-1; ++i)
        {
            int second=find_second(cp, i+1, target-cp[i].first);
            if(second>=0)
            {
                if(cp[i].second<second)
                    return {cp[i].second+1, second+1};
                else
                    return {second+1, cp[i].second+1};
            }
        }

        return res;
    }

private:
    int find_second(const std::vector<std::pair<int, int>>& nums, int start, int target)
    {
        int low = start;
        int high = nums.size()-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(nums[mid].first<target)
            {
                low=mid+1;
            }
            else if(nums[mid].first==target)
            {
                return nums[mid].second;
            }
            else
            {
                high=mid-1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    /*
    std::vector<int> nums{3, 2, 4};
    s.twoSum(nums, 6);
    */

    std::vector<int> nums{150,24,79,50,88,345,3};
    s.twoSum(nums, 200);

    std::cout<<std::endl;
    return 0;
}

