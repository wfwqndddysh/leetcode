#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
    {
        if(nums.size()==0) return subsets_;
        std::sort(nums.begin(), nums.end());

        std::vector<std::pair<bool, int>> flag;
        flag.push_back({false, 1});

        size_t dup_index = 0;
        for(int i=0; i<(int)nums.size()-1; ++i)
        {
            if(nums[i]!=nums[i+1])
            {
                dup_index = i+1;
                flag.push_back({false, 1});
            }
            else
            {
                flag[dup_index].second++;
                flag.push_back({false, 0});
            }
        }

        bfs_backtrack(nums, 0, flag);
        return subsets_;
    }
private:
    void bfs_backtrack(const std::vector<int>& nums, size_t cur, std::vector<std::pair<bool, int>>& flag)
    {
        if(cur==nums.size())
        {
            subsets_.push_back({});
            for(size_t i=0; i<flag.size(); ++i)
            {
                if(flag[i].first)
                    subsets_.back().push_back(nums[i]);
            }
        }
        else
        {
            if(flag[cur].second==1)
            {
                bool candiates[2] = {true, false};
                for(int i=0; i<2; ++i)
                {
                    flag[cur].first = candiates[i];
                    bfs_backtrack(nums, cur+1, flag);
                    flag[cur].first =false;
                }
            }
            else if(flag[cur].second>1)
            {
                bfs_backtrack(nums, cur+flag[cur].second, flag);
                for(int i=0; i<flag[cur].second; ++i)
                {
                    flag[cur+i].first = true;
                    bfs_backtrack(nums, cur+flag[cur].second, flag);
                }
                for(int i=0; i<flag[cur].second; ++i)
                {
                    flag[cur+i].first = false;
                }
            }
        }
    }

private:

    std::vector<std::vector<int>> subsets_;
};

int main()
{
    Solution s;
    //std::vector<int> nums{1, 1};
    std::vector<int> nums{1, 2, 2};
    auto vv = s.subsetsWithDup(nums);

    for(const auto& v : vv)
    {
        for(int n : v)
            std::cout<<n<<" ";
        std::cout<<std::endl;
    }


    std::cout<<std::endl;
    return 0;
}

