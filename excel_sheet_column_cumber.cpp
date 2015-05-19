#include<iostream>
#include<cassert>

class Solution
{
public:
    int titleToNumber(std::string s)
    {
        int num = 0;
        for(size_t i=0; i<s.size(); ++i)
        {
            num = (num*26)+((s[i]-'A')+1);
        }
        return num;
    }
};

int main()
{
    Solution s;
    std::cout<<s.titleToNumber("AAA")<<std::endl;
}

