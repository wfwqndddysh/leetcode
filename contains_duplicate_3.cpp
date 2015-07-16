#include<iostream>
#include<cassert>
#include<vector>
#include<unordered_map>

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
    {
        int sz=nums.size();

        if(!k || k<0 || sz<2) return false;

        std::unordered_map<int64_t, int> num2index;

        for(int i=0; i<sz; ++i)
        {
            int cur_sz=num2index.size();
            if(cur_sz<t)
            {
                for(auto n2i : num2index)
                    if((std::abs(nums[i]-n2i.first)<=t) && -n2i.second<=k)
                        return true;
            }
            else
            {
                for(int64_t j=-t; j<=t; ++j)
                {
                    auto itr=num2index.find(nums[i]+j);
                    if(itr!=num2index.cend() && i-itr->second<=k)
                        return true;
                }
            }
            num2index[nums[i]]=i;
        }

        return false;
    }
};

int main()
{
    Solution s;

    /*
    std::vector<int> nums{-1, -1};
    std::cout<<s.containsNearbyAlmostDuplicate(nums, 1, 0)<<std::endl;
    */

    /*
    std::vector<int> nums{-1, -1};
    std::cout<<s.containsNearbyAlmostDuplicate(nums, 1, -1)<<std::endl;
    */

    /*
    std::vector<int> nums{-3, 3};
    std::cout<<s.containsNearbyAlmostDuplicate(nums, 2, 4)<<std::endl;
    */

    std::vector<int> nums{3, 6, 0, 2};
    std::cout<<s.containsNearbyAlmostDuplicate(nums, 2, 2)<<std::endl;

    return 0;
}

