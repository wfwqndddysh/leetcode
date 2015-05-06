#include<cassert>
#include<iostream>
#include<array>


class Solution
{
public:
    bool isIsomorphic(const std::string& s, const std::string& t)
    {
        if(s.length()!=t.length())
            return false;
            
        size_t map_s_t[256] = { 0 };
        size_t map_t_s[256] = { 0 };

        for(size_t i=0; i<s.length(); i++)
        {
            if(map_s_t[s[i]]!=map_t_s[t[i]])
                return false;

            map_s_t[s[i]] = i+1;
            map_t_s[t[i]] = i+1;
        }
        return true;
    }
};

int main()
{
    Solution s;

    std::string a = "ab";
    std::string b = "aa";

    std::cout<<std::boolalpha<<s.isIsomorphic(a, b)<<std::endl;;
    return 0;
}

