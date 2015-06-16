#include<iostream>
#include<cassert>
#include<vector>
#include<queue>
#include<algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int numTrees(int n)
    {
        if(n==1) return 1;

        std::vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;

        for(int i=3; i<=n; ++i)
        {
            for(int j=1; j<=i; ++j)
            {
                if(j==1 || j==i)
                    dp[i-1] += dp[i-2];
                else
                    dp[i-1] = dp[i-1] + dp[j-2] * dp[i-j-1];
            }
        }

        return dp[n-1];
    }
};

class SolutionRec
{
public:
    int numTrees(int n)
    {
        return rec(1, n);
    }

private:
    int rec(int beg, int end)
    {
        if(beg==end) return 1;
        if(beg+1==end) return 2;

        int num = 0;
        for(int i=beg; i<=end; ++i)
        {
            if(i==beg)
                num += rec(beg+1, end);
            else if(i==end)
                num += rec(beg, end-1);
            else
            {
                num = num + rec(beg, i-1) * rec(i+1, end);
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    std::cout<<s.numTrees(19)<<std::endl;
    return 0;
}

