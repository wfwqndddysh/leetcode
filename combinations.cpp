#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<std::vector<int>> combine(int n, int k)
    {
        num_ = n;
        cnt_ = k;
        std::vector<bool> flags(n, false);
        backtrack(0, 0, flags);
        return combinations_;
    }
    
private:
    void backtrack(int cur, int cnt, std::vector<bool>& flags)
    {
        if(cnt==cnt_)
        {
            combinations_.push_back({});
            for(size_t i=0; i<flags.size(); ++i)
            {
                if(flags[i])
                    combinations_.back().push_back(i+1);
            }
        }
        else if(cur==num_)
        {
            return;
        }
        else
        {

            bool candiates[2] = {true, false};
            for(int i=0; i<2; ++i)
            {
                flags[cur] = candiates[i];
                backtrack(cur+1, flags[cur]==true ? cnt+1 : cnt,  flags);
                flags[cur]=false;
            }
        }
    }

private:
    int num_;
    int cnt_;
    std::vector<std::vector<int>> combinations_;
};

int main()
{
    Solution s;
    auto vv = s.combine(4, 2);

    for(const auto& v : vv)
    {
        for(int n : v)
            std::cout<<n<<" ";
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

