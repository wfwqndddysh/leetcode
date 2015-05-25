#include<iostream>
#include<cassert>
#include<vector>
#include<climits>

class Solution
{
public:
    int maxProduct_dp(const std::vector<int>& nums)
    {
        long max_val = INT_MIN;
        auto sz=nums.size();
        std::vector<std::vector<int64_t>> products(sz+1);
        for(auto& v : products)
            v.resize(sz+1, 1);

        for(size_t i=1; i<sz; ++i)
        {
            for(size_t j=i; j<sz; ++j)
            {
                products[i][j] = products[i][j-1] * nums[j-1];
                max_val = std::max(max_val, products[i][j]);
            }
        }
        return max_val;
    }

    int maxProduct_space_optimize(const std::vector<int>& nums)
    {
        long max_val = INT_MIN;
        auto sz=nums.size();
        std::vector<int64_t> products(sz);

        for(size_t i=0; i<sz; ++i)
        {
            products[i] = nums[i];
            max_val = std::max(max_val, products[i]);
        }

        for(size_t len=2; len<=sz; ++len)
        {
            for(size_t j=0; j<sz-len; ++j)
            {
                if(products[j]==0)
                {
                    products[j]=0;
                }
                else
                {
                    products[j] *= nums[j+len-1];
                }
                max_val = std::max(max_val, products[j]);
            }
        }
        return max_val;
    }

    //leetcode 注意到一个事实，对于整数来说，连续往后面累积，
    //绝对值只增不减，只有一个0是例外的，所以只要扫描一遍就ok
    //循环不变式
    //max_val:到目前最大值
    //max_t:最后一个元素为nums[i]的最大值
    //min_t:最后一个元素为nums[i]的最小值
    //利用了整数的不少性质
    int maxProduct(const std::vector<int>& nums)
    {
        auto sz=nums.size();
        assert(sz>0);

        int max_val = nums[0];
        int min_t = nums[0];
        int max_t = nums[0];
        for(size_t i=1; i<sz; ++i)
        {
            if(nums[i]<0)
            {
                std::swap(max_t, min_t);
            }

            max_t = std::max(nums[i], nums[i]*max_t);
            min_t = std::min(nums[i], nums[i]*min_t);

            max_val = std::max(max_val, max_t);
        }
        return max_val;
    }
};

int main()
{
    Solution s;
    std::vector<int> v{ -5,2,4,1,-2,2,-6,3,-1,-1,-1,-2,-3,5,1,-3,-4,2,-4,6,-1,5,-6,1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,1,1 };
    std::cout<<s.maxProduct(v)<<std::endl;
    return 0;
}

