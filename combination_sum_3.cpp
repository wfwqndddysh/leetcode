#include<iostream>
#include<cassert>
#include<vector>

//允许重复的纯暴力组合
class Solution
{
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        k_=k;
        n_=n;

        std::vector<int> solution;
        backtrack(0, 0, solution);

        return solutions_;
    }

private:
    void backtrack(int cur_count, int cur_sum, std::vector<int> solution)
    {
        if(cur_count==k_ && cur_sum==n_)
        {
            solutions_.push_back(solution);
        }
        else if(cur_count<k_ && cur_sum<n_)
        {
            for(int i=1; i<10; i++)
            {
                if(cur_sum+i<=n_ && cur_sum+1*(k_-cur_count)<=n_ && cur_sum+9*(k_-cur_count)>=n_)
                {
                    solution.push_back(i);
                    backtrack(cur_count+1, cur_sum+i, solution);
                    solution.pop_back();
                }
            }
        }
    }

private:
    int k_;
    int n_;
    std::vector<std::vector<int>> solutions_;
};

//允许数字重复选取的剪枝方案
class Solution_
{
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        k_=k;
        n_=n;

        std::vector<int> solution;
        backtrack(1, 0, solution);

        return solutions_;
    }

private:
    void backtrack(int cur_elem, int cur_sum, std::vector<int> solution)
    {
        if(cur_elem==9)
        {
            int cnt=k_-(int)solution.size();
            if(cur_sum+cnt*9==n_)
            {
                for(int i=0; i<cnt; ++i)
                {
                    solution.push_back(9);
                }
                solutions_.push_back(solution);
            }
        }
        else
        {
            int cnt=calc_candiates_cnt(solution.size(), cur_elem, cur_sum);

            for(int i=0; i<=cnt; i++)
            {
                for(int j=0; j<i; ++j)
                {
                    solution.push_back(cur_elem);
                }

                backtrack(cur_elem+1, cur_sum+i*cur_elem, solution);

                for(int j=0; j<i; ++j)
                {
                    solution.pop_back();
                }
            }
        }
    }

private:
    int calc_candiates_cnt(int cur_count, int candiates, int cur_sum)
    {
        int max_cnt=0;
        for(int i=1; i<=k_-cur_count; ++i)
        {
            if(cur_sum+candiates*i+(k_-cur_count-i)*9<n_)
                break;
            max_cnt=i;
        }

        return max_cnt;
    }

private:
    int k_;
    int n_;
    std::vector<std::vector<int>> solutions_;
};

//real, 不允许数字重复的就简单了
class SolutionReal
{
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        k_=k;
        n_=n;

        std::vector<int> solution;
        backtrack(0, 1, 0, solution);

        return solutions_;
    }

private:
    void backtrack(int cur_count, int cur_elem, int cur_sum, std::vector<int> solution)
    {
        if(cur_count==k_ && cur_sum==n_)
        {
            solutions_.push_back(solution);
        }
        else if(cur_count<k_ && cur_sum<n_ && cur_elem<=9)
        {
            solution.push_back(cur_elem);
            backtrack(cur_count+1, cur_elem+1, cur_sum+cur_elem, solution);
            solution.pop_back();

            backtrack(cur_count, cur_elem+1, cur_sum, solution);
        }
    }

private:
    int k_;
    int n_;
    std::vector<std::vector<int>> solutions_;
};

int main()
{
    SolutionReal s;

    //auto vv=s.combinationSum3(8, 36);
    //auto vv=s.combinationSum3(3, 7);
    auto vv=s.combinationSum3(3, 9);

    for(const auto& v : vv)
    {
        for(int n : v)
            std::cout<<n<<" ";
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

