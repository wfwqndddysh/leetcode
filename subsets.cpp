#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<bool> flag(nums.size());
        std::sort(nums.begin(), nums.end());
        bfs_backtrack(nums, 0, flag);
        return subsets_;
    }
private:
    void bfs_backtrack(const std::vector<int>& nums, size_t cur, std::vector<bool>& flag)
    {
        if(cur==nums.size())
        {
            subsets_.push_back({});
            for(size_t i=0; i<flag.size(); ++i)
            {
                if(flag[i])
                    subsets_.back().push_back(nums[i]);
            }
        }
        else
        {
            bool candiates[2] = {true, false};
            for(int i=0; i<2; ++i)
            {
                flag[cur] = candiates[i];
                bfs_backtrack(nums, cur+1, flag);
                flag[cur]=false;
            }
        }
    }
private:
    std::vector<std::vector<int>> subsets_;
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

