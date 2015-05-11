#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

class Solution
{
public:
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

    void rotate_forward(std::vector<int>& nums, int k)
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

    void rotate_back(std::vector<int>& nums, int k)
    {
        int sz = nums.size();
        k %= sz;

        if(sz<=1 || k==0)
            return;

        for(int cur=sz-1, prev, tmp=nums[cur], init=sz-1, cnt=0;  cur>=0 && cnt<sz; cnt++)
        {
            prev = (cur-k)>=0 ? (cur-k) : (cur-k+sz);
            if(prev>cur && prev==init)
            {
                nums[cur] = tmp;
                init--;
                cur=init;
                tmp = nums[cur];
            }
            else
            {
                nums[cur] = nums[prev];
                cur = prev;
            }
        }
    }

    //详细解释见geeksforgeeks
    //AB-->ArB-->ArBr-->BA
    void rotate_reverse(std::vector<int>& nums, int k)
    {
        int sz = nums.size();
        k %= sz;
        if(sz<=0 || k==0)
            return;
        std::reverse(nums.begin(), nums.begin()+(sz-k));
        std::reverse(nums.begin()+(sz-k), nums.end());
        std::reverse(nums.begin(), nums.end());
    }

    //Gries-Mills 算法，实际测量，性能最好
};

int main()
{
    Solution s;
    std::vector<int> v{1,2,3};
    s.rotate_reverse(v, 2);
    for(auto n : v)
        std::cout<<n<<std::endl;
    return 0;
}

