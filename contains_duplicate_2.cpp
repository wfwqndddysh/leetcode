#include<iostream>
#include<cassert>
#include<vector>
#include<unordered_map>

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
        int sz=nums.size();
        std::unordered_map<int, int> num2index;

        for(int i=0; i<sz; ++i)
        {
            auto itr=num2index.find(nums[i]);
            if(itr!=num2index.cend() && i-itr->second+1>=k)
                return true;

            num2index[nums[i]]=i;
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

