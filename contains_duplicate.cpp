#include<iostream>
#include<cassert>
#include<vector>
#include<unordered_set>

class Solution
{
public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::unordered_set<int> cache;

        for(int n : nums)
        {
            if(cache.count(n)>0)
                return true;
            else
                cache.insert(n);
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

