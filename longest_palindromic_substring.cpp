#include<iostream>
#include<cassert>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        int len=s.length();
        int longest1=0;
        int start1=0;
        for(int i=0; i<len; ++i)
        {
            int cur=1;
            int j=1;
            int start=i;
            for(; i-j>=0 && i+j<len; ++j, cur+=2)
            {
                if(s[i-j]!=s[i+j])
                    break;
                start=i-j;
            }

            if(cur>longest1)
            {
                longest1=cur;
                start1=start;
            }
        }

        int longest2=0;
        int start2=0;
        for(int i=0; i<len-1; ++i)
        {
            if(s[i]!=s[i+1])
                continue;

            int start=i;
            int cur=2;
            for(int j=1; i-j>=0 && i+1+j<len; ++j, cur+=2)
            {
                if(s[i-j]!=s[i+1+j])
                    break;

                start=i-j;
            }

            if(cur>longest2)
            {
                longest2=cur;
                start2=start;
            }
        }

        return longest2>longest1 ? s.substr(start2, longest2) : s.substr(start1, longest1);
    }
};

int main()
{
    Solution s;
    std::cout<<s.longestPalindrome("aaaa")<<std::endl;
    return 0;
}

