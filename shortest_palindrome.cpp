#include<iostream>
#include<cassert>
#include<string>
#include<algorithm>

class Solution
{
public:
    std::string shortestPalindrome(std::string s)
    {
        int sz=s.size();
        if(sz<2) return s;

        int max_odd=1;
        int max_even=0;

        for(int i=1; i<=(sz-1)/2; ++i)
        {
            max_odd=std::max(1, get_longest_palindrome_odd(s, i));
        }

        for(int i=1; i<=(sz-2)/2; ++i)
        {
            max_odd=std::max(1, get_longest_palindrome_odd(s, i));
        }

        std::string min_s=s.substr(std::max(max_odd, max_even));
        std::reverse(min_s.begin(), min_s.end());
        return min_s+s;
    }

private:
    int get_longest_palindrome_odd(const std::string& s, int center)
    {
        for(int beg=0; beg<center; ++beg)
        {
            if(s[beg]!=s[2*center-beg])
                return 1;
        }
        return 2*center+1;
    }

    int get_longest_palindrome_even(const std::string& s, int center)
    {
        for(int beg=0; beg<=center; ++beg)
        {
            if(s[beg]!=s[2*center-beg+1])
                return 0;
        }
        return 2*(center+1);
    }
};

int main()
{
    Solution s;

    std::cout<<s.shortestPalindrome("aacecaaa")<<std::endl;
    std::cout<<s.shortestPalindrome("abcd")<<std::endl;

    return 0;
}

