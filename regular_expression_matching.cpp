#include<iostream>
#include<cassert>
#include<vector>
#include<cstring>

class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        return backtrack(s, 0, p, 0);
    }

private:
    bool backtrack(const std::string& s
            , int cur_s
            , const std::string& p
            , int cur_p)
    {
        int sz_s=s.size();
        int sz_p=p.size();

        if(cur_s==sz_s && cur_p==sz_p)
        {
            return true;
        }
        else if(cur_s==sz_s || cur_p==sz_p)
        {
            if(cur_p!=sz_p)
            {
                int i=cur_p;
                for(; i+1<sz_p; i+=2)
                {
                    if(p[i+1]!='*')
                        break;
                }
                if(i==sz_p) return true;
            }

            return false;
        }
        else
        {
            if(cur_p+1<sz_p && p[cur_p+1]=='*')
            {
                if(p[cur_p]=='.')
                {
                    //for(int i=cur_s; i<=sz_s; ++i)
                    for(int i=sz_s; i>=cur_s; --i)
                    {
                        if(backtrack(s, i, p, cur_p+2))
                            return true;
                    }
                }
                else
                {
                    int cnt=0;
                    while(cur_s+cnt<sz_s && s[cur_s+cnt]==p[cur_p])
                        cnt++;

                    //for(int i=cur_s; i<=cur_s+cnt; ++i)
                    for(int i=cur_s+cnt; i>=cur_s; --i)
                    {
                        if(backtrack(s, i, p, cur_p+2))
                            return true;
                    }
                }
                return false;
            }
            if(p[cur_p]=='.')
            {
                return backtrack(s, cur_s+1, p, cur_p+1);
            }
            else
            {
                return s[cur_s]==p[cur_p] && backtrack(s, cur_s+1, p, cur_p+1);
            }
        }

        return false;
    }

};


/*
关键在于如何处理这个'*'号。

状态：和Mininum Edit Distance这类题目一样。
dp[i][j]表示s[0:i-1]是否能和p[0:j-1]匹配。

递推公式：由于只有p中会含有regular expression，所以以p[j-1]来进行分类。
p[j-1] != '.' && p[j-1] != '*'：dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])
p[j-1] == '.'：dp[i][j] = dp[i-1][j-1]

而关键的难点在于 p[j-1] = '*'。由于星号可以匹配0，1，乃至多个p[j-2]。
1. 匹配0个元素，即消去p[j-2]，此时p[0: j-1] = p[0: j-3]
dp[i][j] = dp[i][j-2]

2. 匹配1个元素，此时p[0: j-1] = p[0: j-2]
dp[i][j] = dp[i][j-1]

3. 匹配多个元素，此时p[0: j-1] = { p[0: j-2], p[j-2], ... , p[j-2] }
dp[i][j] = dp[i-1][j] && (p[j-2]=='.' || s[i-2]==p[j-2])
*/

class SolutionXSS
{
public:
    bool isMatch(const char *s, const char *p) {
        int m = strlen(s), n = strlen(p);
        std::vector<std::vector<bool>> dp(m+1, std::vector<bool>(n+1,false));
        dp[0][0] = true;
        
        for(int i=0; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(p[j-1]!='.' && p[j-1]!='*') {
                    if(i>0 && s[i-1]==p[j-1] && dp[i-1][j-1])
                        dp[i][j] = true;
                }
                else if(p[j-1]=='.') {
                    if(i>0 && dp[i-1][j-1])
                        dp[i][j] = true;
                }
                else if(j>1) {  //'*' cannot be the 1st element
                    if(dp[i][j-1] || dp[i][j-2])  // match 0 or 1 preceding element
                        dp[i][j] = true;
                    else if(i>0 && (p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j]) // match multiple preceding elements
                        dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;

    /*
    std::string str("aaaaaaaaaaaaab");
    std::string pattern("a*a*a*a*a*a*a*a*a*a*a*a*b");
    */

    /*
    std::string str("aa");
    std::string pattern("a*");
    */

    /*
    std::string str("aa");
    std::string pattern(".*");
    */

    std::string str("a");
    std::string pattern("ab*");

    /*
    std::string str("ab");
    std::string pattern(".*c");
    */

    std::cout<<s.isMatch(str, pattern)<<std::endl;
    return 0;
}

