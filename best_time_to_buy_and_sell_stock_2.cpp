#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    //my accepted
    int maxProfit(std::vector<int>& prices)
    {
        int max_profit = 0;
        int sell = -1;
        int low = 0;

        for(int i=1; i<(int)prices.size(); ++i)
        {
            if(prices[i]>prices[low])
            {
                max_profit += prices[i]-prices[low];
                sell = low = i;
            }
            else if(prices[i]<prices[low])
            {
                low = i;
            }
        }
        return max_profit;
    }

    //equal to my accepted, but more simple
    int max_profit(std::vector<int>& prices)
    {
        int max_profit = 0;
        for(int i=1; i<(int)prices.size(); ++i)
        {
            int cur_profit = prices[i]-prices[i-1];
            if(cur_profit>0)
                max_profit += cur_profit;
        }
        return max_profit;
    }
};

int main()
{
    Solution s;
    std::vector<int> stock {1, 2, 4};
    std::cout<<s.max_profit(stock)<<std::endl;
    return 0;
}

