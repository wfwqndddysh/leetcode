#include<iostream>
#include<cassert>
#include<string>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        if(haystack.empty() && needle.empty()) return 0;

        for(size_t i=0; i<haystack.size(); ++i)
        {
            if(haystack.size()-i<needle.size())
                return -1;
            
            size_t j=0;

            while(j<needle.size() && haystack[i+j]==needle[j])
                ++j;

            if(j==needle.size()) return i;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    
    std::string haystack;
    std::string needle;

    std::cout<<s.strStr(haystack, needle)<<std::endl;
    return 0;
}

