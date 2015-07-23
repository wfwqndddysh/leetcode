#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        int sz=nums.size();
        if(sz==0) return {};

        std::vector<int> res(sz, 1);

        res[0]=nums[0];
        for(int i=1; i<sz-1; ++i)
        {
            res[i] = res[i-1]*nums[i];
        }

        int latter=1;
        for(int i=sz-1; i>0; i--)
        {
            res[i]=res[i-1]*latter;
            latter *= nums[i];
        }
        res[0]=latter;

        return res;
    }
};

int main()
{
    Solution s;

    //std::vector<int> nums{0, 0};
    std::vector<int> nums{9, 0, -2};
    auto v=s.productExceptSelf(nums);

    for(int n : v)
        std::cout<<n<<std::endl;

    std::cout<<std::endl;
    return 0;
}

