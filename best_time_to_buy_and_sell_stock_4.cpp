#include<iostream>
#include<cassert>
#include<vector>
#include<vector>
#include<climits>

/*
解题思路

这是网上给出的思路中描述最清晰的一个了
在自己的分析中，这里的思想都出现了，可惜没有继续下去，对于dp类型题来说，坚持是
非常重要的

采用动态规划来解决问题。
我们需要维护如下两个量：
global[i][j]:当前到达第i天最多可以进行j次交易，所得到的最大利润。
local[i][j]:当前到达第i天最多可以进行j次交易，而且最后一次交易在当天卖出，所得
            到的最大利润。

状态转移方程：
global[i][j] = max(local[i][j], global[i-1][j])

上述方程比较两个量的大小：
    1.当前局部最大值；
    2.过往全局最大值。

local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff)
上述方程比较两个量的大小：
    1.全局到i-1天进行j-1次交易，然后加上今天的交易（如果今天的交易赚钱的话）。
    2.取局部第i-1天进行j次交易，然后加上今天的差值（local[i-1][j]是第i-1天卖出
    的交易，它加上diff后变成第i天卖出，并不会增加交易次数。无论diff是正还是负都
    要加上，否则就不满足local[i][j]必须在最后一天卖出的条件了）

另外需要注意的一个问题是，当k远大于数组的大小时，上述算法将变得低效。因此将其改
用不限交易次数的方式解决。
*/

class Solution
{
public:
    int maxProfit(int k, std::vector<int>& prices)
    {
        auto sz = prices.size();
        if(sz<=1)
            return 0;

        if(k>=(int)sz)
            return btbss_3(prices);

        std::vector<int> global(k+1, 0);
        std::vector<int> local(k+1, 0);

        for(int i=1; i<(int)prices.size(); ++i)
        {
            int diff = prices[i]-prices[i-1];
            for(int j=k; j>=1; --j)
            {
                local[j] = std::max(global[j-1]+std::max(diff, 0), local[j]+diff);
                global[j] = std::max(local[j], global[j]);
            }
        }
        return global[k];
    }

    int btbss_3(std::vector<int>& prices)
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
    std::vector<int> stock {3,2,6,5,0,3};
    std::cout<<s.maxProfit(2, stock)<<std::endl;
    return 0;
}

