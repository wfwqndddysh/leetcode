#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    //分治合并法
    int maxProfit(std::vector<int>& prices)
    {
        auto sz = prices.size();
        if(sz<2)
            return 0;

        //第一编扫描，得到在到i天，最到交易2次的最大收益
        std::vector<int> max_forward(sz, 0);
        int low = prices[0];
        for(size_t i=1; i<sz; ++i)
        {
            if((prices[i]-low)>max_forward[i-1])
            {
                max_forward[i] = prices[i]-low;
            }
            else
            {
                max_forward[i] = max_forward[i-1];
                if(prices[i]<low)
                {
                    low = prices[i];
                }
            }
        }

        //第二编扫描，得到从i到n天，最多交易2次的最大值
        std::vector<int> max_backward(sz, 0);
        int high = prices[sz-1];
        for(int i=sz-2; i>=0; --i)
        {
            if((high-prices[i])>max_backward[i-1])
            {
                max_backward[i] = high-prices[i];
            }
            else
            {
                max_backward[i] = max_backward[i+1];
                if(prices[i]>high)
                    high = prices[i];
            }
        }

        //第三编扫描上面的到的两个数组，的出结果
        int max_profit = 0;
        for(size_t i=0; i<sz; ++i)
        {
            int cur = max_forward[i]+max_backward[i];
            if(cur>max_profit)
            {
                max_profit = cur;
            }
        }
        return max_profit;
    }

    //省去第三次遍历
    int max_profit_optimize(std::vector<int>& prices)
    {
        auto sz = prices.size();
        if(sz<2)
            return 0;

        int max_profit = 0;

        //第一编扫描，得到在到i天，最到交易2次的最大收益
        std::vector<int> max_forward(sz, 0);
        int low = prices[0];
        for(size_t i=1; i<sz; ++i)
        {
            if((prices[i]-low)>max_forward[i-1])
            {
                max_forward[i] = prices[i]-low;
            }
            else
            {
                max_forward[i] = max_forward[i-1];
                if(prices[i]<low)
                {
                    low = prices[i];
                }
            }
        }

        //第二编扫描，得到从i到n天，最多交易2次的最大值
        std::vector<int> max_backward(sz, 0);
        int high = prices[sz-1];
        for(int i=sz-2; i>=0; --i)
        {
            if((high-prices[i])>max_backward[i-1])
            {
                max_backward[i] = high-prices[i];
            }
            else
            {
                max_backward[i] = max_backward[i+1];
                if(prices[i]>high)
                    high = prices[i];
            }

            int cur = max_forward[i]+max_backward[i];
            if(cur > max_profit)
                max_profit = cur;
        }
        return max_profit;
    }
};

int main()
{
    Solution s;
    std::vector<int> stock {6,1,3,2,4,7};
    std::cout<<s.maxProfit(stock)<<std::endl;
    return 0;
}

