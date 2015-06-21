#include<iostream>
#include<cassert>
#include<vector>
#include<stack>

class SolutionLeetCode
{
public:
    int largestRectangleArea(std::vector<int> &height)
    {
        int n=height.size();
        if(n==0) return 0;
        if(n==1) return height[0];

        height.push_back(0);
        n++;

        int ans=0;
        std::stack<int> s;

        int i=0,j=0,h=0;
        while(i<n)
        {
            if(s.empty() || height[i]>height[s.top()])
                s.push(i++);
            else
            {
                h=height[s.top()];
                s.pop();
                j= s.empty() ? -1:s.top();
                ans=std::max(ans,h*(i-j-1));
            }
        }
        return ans;
    }
};

class SolutionDP
{
public:
    int largestRectangleArea(std::vector<int>& height)
    {
        int sz=height.size();
        int max_rect(0);
        std::vector<std::vector<int>> dp(sz, std::vector<int>(sz, 0));

        for(int i=0; i<sz; ++i)
        {
            int cur = height[i];

            for(int j=0; j<i; ++j)
            {
                if(dp[j][i-1]<cur)
                {
                    dp[j][i] = dp[j][i-1];
                }
                else
                {
                    dp[j][i] = cur;
                }
                max_rect = std::max(max_rect, (i-j+1)*dp[j][i]);
            }
            dp[i][i] = cur;

            max_rect = std::max(max_rect, cur);
        }

        return max_rect;
    }
};

int main()
{
    SolutionLeetCode s;
    //std::vector<int> height{4, 2};
    std::vector<int> height{1, 2, 3, 4, 5};
    std::cout<<s.largestRectangleArea(height)<<std::endl;
    return 0;
}

