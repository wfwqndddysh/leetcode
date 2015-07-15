#include<iostream>
#include<cassert>
#include<vector>
#include<string>

class Solution
{
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums)
    {
        auto sz=nums.size();
        std::vector<std::string> ranges;
        if(sz==0) return ranges;
        if(sz==1)
        {
            ranges.push_back(std::to_string(nums[0]));
            return ranges;
        }

        int beg=nums[0];

        for(size_t i=1; i<sz; ++i)
        {
            if(nums[i]>nums[i-1]+1)
            {
                if(nums[i-1]>beg)
                {
                    ranges.push_back(std::to_string(beg)+"->"+std::to_string(nums[i-1]));
                }
                else
                {
                    ranges.push_back(std::to_string(beg));
                }
                beg=nums[i];
            }
        }

        if(nums[sz-1]>beg)
        {
            ranges.push_back(std::to_string(beg)+"->"+std::to_string(nums[sz-1]));
        }
        else
        {
            ranges.push_back(std::to_string(beg));
        }

        return ranges;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{1, 3};
    auto vs=s.summaryRanges(nums);

    for(const auto& str : vs)
        std::cout<<str<<std::endl;

    std::cout<<std::endl;
    return 0;
}

