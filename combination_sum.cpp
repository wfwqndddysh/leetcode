#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> real_candidates;
        std::unique_copy(candidates.cbegin(), candidates.cend(), back_inserter(real_candidates));

        std::vector<int> combination;
        backtrack(real_candidates, 0, 0, combination, target);

        return combinations_;
    }

private:
    void backtrack(const std::vector<int>& candidates
            , int cur
            , int sum
            , std::vector<int>& combination
            , int target)
    {
        if(sum==target)
        {
            combinations_.push_back(combination);
            return;
        }
        else if(sum>target)
        {
            return;
        }
        else if(cur==(int)candidates.size())
        {
            return;
        }
        else
        {
            int sz=0;
            int cnt=target/candidates[cur];
            for(int i=0; i<=cnt; ++i)
            {
                if(i>0) combination.push_back(candidates[cur]);
                sz=combination.size();

                backtrack(candidates, cur+1, sum+candidates[cur]*i, combination, target);

                while((int)combination.size()>sz) combination.pop_back();
            }
        }
    }

private:
    std::vector<std::vector<int>> combinations_;
};

int main()
{
    Solution s;
    std::vector<int> candidates(1, 1);

    auto vv = s.combinationSum(candidates, 1);

    for(const auto& v : vv)
    {
        for(int n : v)
            std::cout<<n<<" "<<std::endl;
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

