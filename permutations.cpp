#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<bool> flags(nums.size(), false);

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
            for(size_t i=0; i<nums.size(); ++i)
            {
                if(!flags[i])
                {
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

class SolutionNext
{
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> perms;
        int n=nums.size();
        if(n==0) return perms;

        std::sort(nums.begin(), nums.end());
        perms.push_back(nums);

        for(;;)
        {
            int j=n-2;
            for(; j>=0; --j)
            {
                if(nums[j]<nums[j+1]) break;
            }

            if(j==-1) break;

            int min_i=-1;
            int min = 10;
            for(int m=n-1; m>j; --m)
            {
                if(nums[m]>nums[j] && nums[m]<min)
                {
                    min_i = m;
                    min = nums[m];
                }
            }

            std::swap(nums[j], nums[min_i]);

            std::reverse(nums.begin()+j+1, nums.end());
            perms.push_back(nums);
        }

        return perms;
    }
};

int main()
{
    Solution s;
    SolutionNext sn;

    std::vector<int> nums{0, 1};
    auto vv = sn.permute(nums);

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

