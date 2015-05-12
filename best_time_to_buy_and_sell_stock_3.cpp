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
    }
};

int main()
{
    Solution s;
    std::vector<int> stock {1, 2, 4};
    std::cout<<s.maxProfit(stock)<<std::endl;
    return 0;
}

