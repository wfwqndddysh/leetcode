#include<iostream>
#include<cassert>
#include<string>
#include<unordered_map>

class Solution
{
public:
    bool isAnagram(const std::string& s, const std::string& t)
    {
        if(s.length()!=t.length()) return false;

        std::unordered_map<char, int> c2cnt;
        for(char c : s) c2cnt[c]++;

        for(char c : t)
        {
            if(c2cnt[c]--==0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

