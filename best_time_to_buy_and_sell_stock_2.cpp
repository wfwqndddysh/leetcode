#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        if(prices.size()<2)
            return 0;

        int max_profit = 0;
        int sell = -1;
        int low = 0;

        for(int i=0; i<(int)prices.size(); ++i)
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
};

int main()
{
    Solution s;
    std::vector<int> stock {1, 2, 4};
    std::cout<<s.maxProfit(stock)<<std::endl;
    return 0;
}


/*
if(max_profit>0)
{
    if((sell+1)==i)
    {
        if(prices[i]>prices[sell])
        {
            max_profit += prices[i]-prices[sell];
            sell = i;
        }
        else if(prices[i]<prices[sell])
        {
            low = i;
        }
    }
    else
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
}
else
{
    if(prices[i]>prices[low])
    {
        max_profit = prices[i]-prices[low];
        sell = low = i;
    }
    else if(prices[i]<prices[low])
    {
        low = i;
    }
}
*/

