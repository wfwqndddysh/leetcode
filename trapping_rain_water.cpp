#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int trap(std::vector<int>& height)
    {
        std::vector<int> max_forward(height.size(), 0);
        std::vector<int> max_backward(height.size(), 0);

        int ret=0;
        auto sz=height.size();
        if(sz<3) return ret;

        for(size_t i=0; i<sz-1; ++i)
        {
            max_forward[i+1]=std::max(max_forward[i], height[i]);
        }

        for(size_t i=sz-1; i>=1; --i)
        {
            max_backward[i-1]=std::max(max_backward[i], height[i]);
        }

        for(size_t i=1; i<sz-1; ++i)
        {
            int peak = std::min(max_forward[i], max_backward[i])-height[i];
            ret += std::max(peak, 0);
        }

        return ret;
    }
};

int main()
{
    Solution s;
    std::vector<int> height{};
    std::cout<<s.trap(height)<<std::endl;
    return 0;
}

