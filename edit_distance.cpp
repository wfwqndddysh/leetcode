#include<iostream>
#include<cassert>
#include<string>
#include<vector>

class Solution
{
public:
    int minDistance(const std::string& word1, const std::string& word2)
    {
        int sz_1=word1.size();
        int sz_2=word2.size();

        std::vector<std::vector<int>> dp(sz_1, std::vector<int>(sz_2, 0));

        for(int j=0; j<sz_2; ++j)
        {
            dp[0][j]=j;
        }

        for(int i=1; i<sz_1; ++i)
        {
            for(int j=1; j<sz_2; ++j)
            {
            }
        }

        return dp[sz_1-1][sz_2-1];
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

