#include<iostream>
#include<cassert>
#include<string>
#include<queue>
#include<unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(const std::string& s)
    {
        std::unordered_map<char, int> c2cnt;

        int len=s.length();
        int longest=0;
        int start=0;
        int i=0;

        for(; i<len; )
        {
            if(c2cnt.count(s[i])>0)
            {
                longest=std::max(longest, i-start);

                int repearted=c2cnt[s[i]];

                for(int j=start; j<=repearted; ++j)
                    c2cnt.erase(c2cnt.find(s[j]));

                start=repearted+1;
            }
            else
            {
                c2cnt.insert({s[i],i});
                i++;
            }
        }

        return std::max(longest, i-start);
    }
};

class SolutionLeetCode
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::vector<int> flag(256, -1);
        int start = 0, longest = 0, len = s.size();
        for (int i = 0; i != len; ++i)
        {
            if (flag[s[i]] >= start)
            {
                longest = std::max(longest, i - start);
                start = flag[s[i]] + 1;
            }
            flag[s[i]] = i;
        }
        return std::max(longest, len - start);
    }
};

int main()
{
    Solution s;
    //std::cout<<s.lengthOfLongestSubstring("c")<<std::endl;
    //std::cout<<s.lengthOfLongestSubstring("aa")<<std::endl;
    //std::cout<<s.lengthOfLongestSubstring("gsqygebs")<<std::endl;
    //std::cout<<s.lengthOfLongestSubstring("dvdf")<<std::endl;
    //std::cout<<s.lengthOfLongestSubstring("eee")<<std::endl;
    std::cout<<s.lengthOfLongestSubstring("aaaa")<<std::endl;
    return 0;
}

