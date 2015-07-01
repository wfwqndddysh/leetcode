#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        std::vector<int> count_per_candidates(1, 1);
        for(size_t i=1; i<candidates.size(); ++i)
        {
            if(candidates[i]!=candidates[i-1])
                count_per_candidates.push_back(1);
            else
            {
                count_per_candidates.back()++;
            }
        }
        std::vector<int> real_candidates;
        std::unique_copy(candidates.cbegin(), candidates.cend(), back_inserter(real_candidates));

        std::vector<int> combination;
        backtrack(real_candidates, count_per_candidates, 0, 0, combination, target);
        return combinations_;
    }

private:
    void backtrack(const std::vector<int>& candidates
            , const std::vector<int>& count_per_candidates
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
            int cnt=count_per_candidates[cur];
            for(int i=0; i<=cnt; ++i)
            {
                if(i>0) combination.push_back(candidates[cur]);
                sz=combination.size();

                backtrack(candidates, count_per_candidates, cur+1, sum+candidates[cur]*i, combination, target);

                while((int)combination.size()>sz) combination.pop_back();
            }
        }
    }

private:
    std::vector<std::vector<int>> combinations_;
};

class SolutionLeetCode
{
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &num, int target) {
        std::vector<std::vector<int> > allSol;
        if(num.empty()) return allSol;
        sort(num.begin(),num.end());
        std::vector<int> sol;
        findCombSum2(num, 0, target, sol, allSol);
        return allSol;
    }

    void findCombSum2(std::vector<int> &num, int start, int target, std::vector<int> &sol, std::vector<std::vector<int> > &allSol) {
        if(target==0) {
            allSol.push_back(sol);
            return;
        }

        for(int i=start; i<num.size(); i++) {
            if(i>start && num[i]==num[i-1]) continue;
            if(num[i]<=target) {
                sol.push_back(num[i]);
                findCombSum2(num, i+1, target-num[i], sol, allSol);
                sol.pop_back();
            }
        }
    }
};

/*
注意这两种思路的不同之处
第一种按照算法设计手册模板来做，非常熟悉
第二种却更加需要注意
1,1,1,1,2
在第一次前进时已经用过1个1， 两个1，三个1， 四个1
所以后面回溯到1时就直接退出，因为小于等于4个1的情况已经处理过了
if(i>start && num[i]==num[i-1]) continue;
这一句过滤了所有这种回溯
*/


int main()
{
    SolutionLeetCode s;
    //std::vector<int> candidates{10,1,1,2,7,6,1,5};
    std::vector<int> candidates{1,1,1};

    auto vv = s.combinationSum2(candidates, 2);

    for(const auto& v : vv)
    {
        for(int n : v)
            std::cout<<n<<" ";
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

