#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    //最直接的方法
    int maxProfit(std::vector<int>& prices)
    {
        if(prices.size()<2)
            return 0;

        int money = prices[1]>prices[0] ? prices[1]-prices[0] : 0;
        int cur_low = prices[1]>prices[0] ? prices[0] : prices[1];

        for(size_t i=2; i<prices.size(); ++i)
        {
            if((prices[i]-cur_low)>money)
            {
                money = prices[i]-cur_low;
            }
            else if(prices[i]<cur_low)
            {
                cur_low = prices[i];
            }
        }
        return money;
    }
};

int main()
{
    return 0;
}

