#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    void rotate(std::vector<int>& nums, int k)
    {
        auto sz = nums.size();
        std::vector<int> tmp(sz);

        for(size_t i=0; i<sz; ++i)
        {
            tmp[(i+k)%sz] = nums[i];
        }
        nums = tmp;
    }
};

int main()
{
    Solution s;
    std::vector<int> v = {1, 2, 3};
    s.rotate(v, 2);
    for(auto n : v)
        std::cout<<n<<std::endl;
    return 0;
}

