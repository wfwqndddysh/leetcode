#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        std::vector<bool> flags(nums.size(), false);
        std::sort(nums.begin(), nums.end());

        std::vector<int> perm;
        backtrack(nums, 0, perm, flags);
        return perms_;
    }
private:
    void backtrack(std::vector<int>& nums, int cur, std::vector<int>& perm, std::vector<bool>& flags)
    {
        if(cur==(int)nums.size())
        {
            perms_.push_back(perm);
            return;
        }
        else
        {
            bool has_prev = false;
            int prev = -1;
            for(size_t i=0; i<nums.size(); ++i)
            {
                if(!flags[i] && (i== 0 ? true : has_prev ? nums[i]!=prev : true))
                {
                    if(!has_prev)
                    {
                        has_prev = true;
                    }
                    prev = nums[i];

                    flags[i]=true;
                    perm.push_back(nums[i]);
                    backtrack(nums, cur+1, perm, flags);

                    flags[i]=false;
                    perm.pop_back();
                }
            }
        }
    }

private:
    std::vector<std::vector<int>> perms_;
};

int main()
{
    Solution s;

    std::vector<int> nums{1, 1, 2};
    auto vv = s.permuteUnique(nums);

    for(const auto& v : vv)
    {
        for(int i : v)
            std::cout<<i<<" ";
        std::cout<<std::endl;
    }

    //std::cout<<s.getPermutation(3, 4)<<std::endl;
    //std::cout<<s.getPermutation(9, 331987)<<std::endl;
    std::cout<<std::endl;
    return 0;
}

