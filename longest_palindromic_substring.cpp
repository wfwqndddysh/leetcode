#include<iostream>
#include<cassert>
#include<vector>

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

class SolutionLeetCode
{
public:
    std::string longestPalindrome(const std::string& s)
    {
        if(s.size()<2) return s;

        std::string tmp("?");
        for(size_t i=0; i<s.length(); ++i)
        {
            tmp.push_back(s[i]);
            tmp.push_back('#');
        }
        int len=tmp.size();
        tmp[len-1]='*';

        int longest=0;
        int start=-1;
        std::vector<int> rad(len, 0);
        for (int i=1,j=0,k; i<len; )
        {
            while (tmp[i-j-1]==tmp[i+j+1] )
            {
                j++;  //扫描得出rad值
            }

            rad[i]=j;
            if(j>longest || (j==longest && tmp[i]=='#'))
            {
                longest=j;
                start=i-j;
            }
            for (k=1; k<=j && rad[i-k]!=rad[i]-k; k++)
            {
                rad[i+k]=std::min(rad[i-k],rad[i]-k);  //k指针扫描
            }

            i+=k;  //i跳到下一个需要计算rad值的位置
            j=std::max(j-k,0);  //更新下一个rad值的初始值
        }

        std::string res;
        for(int i=0; i<=2*longest; ++i)
            if(tmp[i+start]!='#')
                res.push_back(tmp[i+start]);

        return res;
    }
};

int main()
{
    SolutionLeetCode s;
    //std::cout<<s.longestPalindrome("aaaa")<<std::endl;
    //std::cout<<s.longestPalindrome("bb")<<std::endl;
    //std::cout<<s.longestPalindrome("ccc")<<std::endl;
    std::cout<<s.longestPalindrome("abb")<<std::endl;
    return 0;
}

