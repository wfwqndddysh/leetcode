#include<iostream>
#include<cassert>
#include<string>
#include<vector>

class SolutionDP
{
public:
    int minDistance(const std::string& word1, const std::string& word2)
    {
        int m=word1.size();
        int n=word2.size();

        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

        for(int i=1; i<=m; ++i)
        {
            dp[i][0]=i;
        }
        for(int j=1; j<=n; ++j)
        {
            dp[0][j]=j;
        }


        for(int i=1; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=std::min(dp[i][j-1], std::min(dp[i-1][j], dp[i-1][j-1]))+1;
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    SolutionDP s;

    std::string word1{"a"};
    std::string word2{"b"};

    std::cout<<s.minDistance(word1, word2)<<std::endl;
    return 0;
}

