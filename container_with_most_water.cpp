#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int res = 0, n = height.size();
        int left = 0, right = n-1;
        while(left < right)
        {
            res = std::max(res, (right-left)*std::min(height[left], height[right]));
            if(height[left] < height[right])
                left++;
            else right--;
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

