#include<iostream>
#include<cassert>
#include<string>
#include<algorithm>
#include<vector>

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

class Solution_
{
public:
    std::string shortestPalindrome(std::string s)
    {
        int sz=s.size();
        if(sz<2) return s;

        int longest_from_head=longestPalindromeHead(s);
        std::string min_s=s.substr(longest_from_head);
        std::reverse(min_s.begin(), min_s.end());
        return min_s+s;
    }

private:
    int longestPalindromeHead(const std::string& s)
    {
        if(s.size()<2) return s.size();
        int res=0;

        std::string tmp("?");
        for(size_t i=0; i<s.length(); ++i)
        {
            tmp.push_back(s[i]);
            tmp.push_back('#');
        }
        int len=tmp.size();
        tmp[len-1]='*';

        std::vector<int> rad(len, 0);
        for (int i=1,j=0,k; i<len; )
        {
            while (tmp[i-j-1]==tmp[i+j+1] )
            {
                j++;  //扫描得出rad值
            }

            rad[i]=j;
            if(i-j==1)
            {
                res=std::max(res, j+1);
            }
            for (k=1; k<=j && rad[i-k]!=rad[i]-k; k++)
            {
                rad[i+k]=std::min(rad[i-k],rad[i]-k);  //k指针扫描
            }

            i+=k;  //i跳到下一个需要计算rad值的位置
            j=std::max(j-k,0);  //更新下一个rad值的初始值
        }

        return res;
    }
};

int main()
{
    Solution_ s;

    //std::cout<<s.shortestPalindrome("aacecaaa")<<std::endl;
    //std::cout<<s.shortestPalindrome("abcd")<<std::endl;

    std::cout<<s.shortestPalindrome("aba")<<std::endl;

    return 0;
}

