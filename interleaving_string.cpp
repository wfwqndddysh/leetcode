#include<iostream>
#include<cassert>
#include<vector>
#include<string>


/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

*/
//贪心+回塑----其实就是暴力法啦，超时
class Solution
{
public:
    bool isInterleave(const std::string& s1
            , const std::string& s2
            , const std::string& s3)
    {
        return rec(s1, 0, s2, 0, s3, 0) || rec(s2, 0, s1, 0, s3, 0);
    }

private:
    bool rec(const std::string& cur, int ci
            , const std::string& next, int ni
            , const std::string& dest, int di)
    {
        int max_eat = 0;
        int l_cur = cur.size();
        int l_next = next.size();
        int l_dest = dest.size();

        if(di==l_dest && ci==l_cur && ni==l_next) return true;

        for(; dest[di]==cur[ci] && ci<l_cur&& di<l_dest; )
        {
            max_eat++;
            ci++;
            di++;
        }

        for(int i=max_eat; i>0; --i)
        {
            if(rec(next, ni, cur, ci, dest, di))
                return true;
            ci--;
            di--;
        }

        return false;
    }
};

class SolutionDP
{
public:
    bool isInterleave(const std::string& s1
            , const std::string& s2
            , const std::string& s3)
    {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();

        if(l1+l2!=l3) return false;
        if(l1==0) return s2==s3;
        if(l2==0) return s1==s3;

        std::vector<std::vector<bool>> dp(l1+1, std::vector<bool>(l2+1, false));

        for(int i=1; i<=l1; ++i)
        {
            if(s1[i-1]!=s3[i-1])
                break;
            dp[i][0]=true;
        }

        for(int j=1; j<=l2; ++j)
        {
            if(s2[j-1]!=s3[j-1])
                break;
            dp[0][j]=true;
        }

        for(int i=1; i<=l1; ++i)
        {
            for(int j=1; j<=l2; ++j)
            {
                dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[l1][l2];
    }
};

int main()
{
    SolutionDP s;

    //std::string s1("ab");
    //std::string s2("bc");
    //std::string s3("babc");

    std::string s1("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa");
    std::string s2("babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab");
    std::string s3("babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");

    //std::string s1 = "aabaac";
    //std::string s2 = "aadaaeaaf";
    //std::string s3 = "aadaaeaabaafaac";

    //std::string s1 = "a";
    //std::string s2 = "b";
    //std::string s3 = "ab";

    std::cout<<s.isInterleave(s1, s2, s3)<<std::endl;
    return 0;
}

