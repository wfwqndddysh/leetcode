#include<climits>
#include<iostream>
#include<cassert>
#include<vector>
#include<unordered_map>
#include<unordered_set>

class Solution
{
public:
    int longestConsecutive(const std::vector<int> nums)
    {
        auto sz=nums.size();
        if(sz<2) return sz;

        std::unordered_set<int> s;

        int longest = 1;
        for(size_t i=0; i<sz; ++i)
        {
            s.insert(nums[i]);
        }

        for(int i : nums)
        {
            int l = 1;

            int left=i-1;
            int right=i+1;

            while(s.count(left)>0)
            {
                s.erase(s.find(left));
                l++;
                left--;
            }

            while(s.count(right)>0)
            {
                s.erase(s.find(right));
                l++;
                right++;
            }

            longest = std::max(longest, l);
        }

        return longest;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums;
    std::cout<<s.longestConsecutive(nums)<<std::endl;
    return 0;
}

