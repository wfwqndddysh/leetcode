#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<bool> flags(n, false);
        backtrack(0, 0, flags);
        return combinations_;
    }
    
private:
    void backtrack(int cur, int cnt, std::vector<bool>& flags)
    {
        bool candiates[2] = {true, false};
    }

private:
    int cnt_ = 0;
    std::vector<std::vector<int>> combinations_;
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

