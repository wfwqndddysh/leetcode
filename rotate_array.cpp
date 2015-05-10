#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    /*
    void rotate(std::vector<int>& nums, int k)
    {
        auto sz = nums.size();
        k %= sz;
        std::vector<int> tmp(sz);

        for(size_t i=0; i<sz; ++i)
        {
            tmp[(i+k)%sz] = nums[i];
        }
        nums = tmp;
    }
    */

    void rotate(std::vector<int>& nums, int k)
    {
        auto sz = nums.size();
        k %= sz;

        if(sz==0 || k==0)
            return;

        size_t cur = 0;
        size_t init = 0;
        size_t tmp_prev = nums[sz-k];
        bool start = false;

        for(size_t i=0; i<sz; ++i)
        {
            if(cur==init && start)
            {
                ++init;
                cur = init;
                tmp_prev = nums[sz-k+cur];
                start = false;
            }
            start = true;
            int tmp = nums[cur];
            nums[cur] = tmp_prev;
            tmp_prev = tmp;
            cur = (cur+k)%sz;
        }
    }
};

int main()
{
    Solution s;
    std::vector<int> v{1,2,3,4,5,6};
    s.rotate(v, 2);
    for(auto n : v)
        std::cout<<n<<std::endl;
    return 0;
}

