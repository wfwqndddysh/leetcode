#include<iostream>
#include<cassert>
#include<vector>
#include<string>

class Solution
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        n_=n;
        int used_pairs=0;
        int left_pare=0;
        std::string parenthesis;
        backtrack(0, left_pare, used_pairs, parenthesis);
        return parenthesis_;
    }

private:
    void backtrack(int cur
            , int left_pare
            , int used_pairs
            , std::string& parenthesis)
    {
        if(cur==2*n_)
        {
            parenthesis_.push_back(parenthesis);
        }
        else
        {
            int left = n_-used_pairs-left_pare;
            int right = n_-used_pairs;

            if(left>0)
            {
                parenthesis.push_back('(');
                backtrack(cur+1, left_pare+1, used_pairs, parenthesis);
                parenthesis.pop_back();
            }

            if(left_pare>0 && right>0)
            {
                parenthesis.push_back(')');
                backtrack(cur+1, left_pare-1, used_pairs+1, parenthesis);
                parenthesis.pop_back();
            }
        }
    }

private:
    int n_;
    std::vector<std::string> parenthesis_;
};

class SolutionMyClean
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        if(n<=0) return solutions_;
        n_ = n;

        std::string solution;
        backtrack(solution, 0, 0);
        return solutions_;
    }
private:
    void backtrack(std::string& solution, int open_used, int close_used)
    {
        if(open_used==close_used && open_used==n_)
        {
            solutions_.push_back(solution);
        }
        else if(close_used>open_used || open_used>n_)
        {
            return;
        }

        size_t sz=solution.size();
        solution.push_back('(');
        backtrack(solution, open_used+1, close_used);

        //restore
        while(solution.size()!=sz) solution.erase(--solution.end());

        if(open_used>close_used)
        {
            solution.push_back(')');
            backtrack(solution, open_used, close_used+1);
        }
    }

    int n_;
    std::vector<std::string> solutions_;
};

int main()
{
    Solution s;

    auto v=s.generateParenthesis(3);

    for(const auto& parenthesis : v)
        std::cout<<parenthesis<<std::endl;

    std::cout<<std::endl;
    return 0;
}

