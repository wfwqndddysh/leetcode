#include<iostream>
#include<cassert>
#include<string>
#include<vector>

class SolutionDP
{
public:
    bool isMatch(std::string s, std::string p)
    {
        auto m=p.size();
        auto n=s.size();

        if(m==0 && n==0)
            return true;
        else if(m==0)
            return false;
        else if(n==0)
        {
            bool all = true;
            for(size_t i=0; i<m; ++i)
                all = all && p[i]=='*';
            return all;
        }

        std::vector<std::vector<bool>> dp(m, std::vector<bool>(n, true));

        bool has_eat = false;
        if(p[0]!='*')
        {
            has_eat = true;
            dp[0][0] = p[0]==s[0] || p[0]=='?';
        }

        for(size_t i=1; i<m; ++i)
        {
            if(!dp[i-1][0])
                dp[i][0]=false;
            else if(p[i]!='*')
            {
                if(has_eat)
                    dp[i][0]=false;
                else if(p[i]==s[0])
                {
                    has_eat = true;
                    dp[i][0]=true;
                }
            }
        }

        for(size_t j=1; j<n; ++j)
        {
            if(p[0]!='*') dp[0][j]=false;
        }

        for(size_t i=1; i<m; ++i)
        {
            for(size_t j=1; j<n; ++j)
            {
                if(p[i]=='*')
                {
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else if(p[i]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j-1] && p[i]==s[j];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

class SolutionBacktrack
{
public:
    bool isMatch(std::string s, std::string p)
    {
        auto m=p.size();
        auto n=s.size();

        if(m==0 && n==0)
            return true;
        else if(m==0)
            return false;
        else if(n==0)
        {
            bool all = true;
            for(size_t i=0; i<m; ++i)
                all = all && p[i]=='*';
            return all;
        }

        bool  ret=backtrack(s, p, 0, 0);
        std::cout<<cnt_<<std::endl;
        return ret;
    }
    bool backtrack(const std::string& s
            , const std::string& p
            , size_t cur_s
            , size_t cur_p)
    {
        if(cur_s==s.size() && cur_p==p.size())
        {
            return true;
        }
        else if(cur_s==s.size())
        {
            for(size_t i=cur_p; i<p.size(); ++i)
            {
                if(p[i]!='*') return false;
            }
            return true;
        }
        else if(cur_p==p.size())
        {
            return false;
        }
        else
        {
            if(p[cur_p]=='*')
            {
                while(cur_p+1<p.size() && p[cur_p+1]=='*') cur_p++;
                for(size_t i=cur_s; i<s.size(); ++i)
                {
                    if(i!=cur_s) cnt_++;
                    if(backtrack(s, p, i, cur_p+1)) return true;
                }
            }
            else if(p[cur_p]=='?')
            {
                return backtrack(s, p, cur_s+1, cur_p+1);
            }
            else
            {
                return p[cur_p]==s[cur_s] && backtrack(s, p, cur_s+1, cur_p+1);
            }
        }

        return false;
    }

private:
    int cnt_;
};

class SolutionLeetCode
{
public:
    bool isMatch(const std::string str, const std::string parttern)
    {
        cnt_ = 0;
        const char* s=str.c_str();
        const char* p=parttern.c_str();
        const char* star=NULL;
        const char* ss=s;
        while (*s)
        {
            if ((*p=='?')||(*p==*s))
            {
                s++;
                p++;
                continue;
            }

            if (*p=='*')
            {
                star=p++;
                ss=s;
                continue;
            }

            if(star)
            {
                cnt_++;
                p = star+1;
                s=++ss;
                continue;
            }

            return false;
        }
        while (*p=='*'){p++;}

        std::cout<<cnt_<<std::endl;
        
        return !*p;
    }
    
private:
    int cnt_;
};

int main()
{
    /*
    std::string str("aa");
    std::string parttern("*");
    */

    /*
    std::string str("ab");
    std::string parttern("*a");
    */

    /*
    std::string str("");
    std::string parttern("*");
    */

    /*
    std::string str("a");
    std::string parttern("aa");
    */

    /*
    std::string str("c");
    std::string parttern("*?*");
    */

    /*
    std::string str("mississippi");
    std::string parttern("m*si*");
    */

    /*
    std::string str("babbbaabbaaaaabbababaaaabbbbbbbbbbabbaaaabbababbabaa");
    std::string parttern("**a****a**b***ab***a*bab");
    */

    /*
    std::string str("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba");
    std::string parttern("*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*");
    */

    /*
    std::string str("bbbbabbbaabaaaaaaabbabbaaaaabbaaabaabbbbbbbabbaaabbabaababbbabaabababababaababbaaaababbaaabaababbbbaaabbabaaababbbababbaabaaaabaaaaaabbababbbbababaaaaaabaabbbbbbabbbaaaabaaaabbbbbabaaaabababaabbbbabba");
    std::string parttern("*bababa*b*ba*abab****a**b**baa****a*aabb**b****ab**a***a*bb*b*b**bb*b**b*aab**babaaa**ab*babbba***baba");
    */

    /*
    std::string str("aaabbbabbababaababbbbbabbaaaaabbbbaaaabaaaabbabbbaaababaaaabababbaababbaabbbbaabaabaababbbabaabbabbaaaaaabbbabaabaaabbbaabbabaabbbbabbabaababbbbbbbaaaaababaabbaaaabbabbaaaabbbbaabbaabbaababaabaabbbaab");
    std::string parttern("******a****aa**a**aa**aa**ba**aba*aa*b*a*bb**a*****b*******bb******a*aa*bbba*a*ba***baa*a*abb***ab*ab");
    */

    /*
    std::string str("ababbbaabbaaaababaabbbbbabaababbbaabbbbaabaabbbaabb");
    std::string parttern("*a**a*a");
    */

    std::string str("bbaaaaaabbbbbabbabbaabbbbababaaabaabbababbbabbababbaba");
    std::string parttern("b*b*ba**a*aaa*a*b**bbaa");

    SolutionLeetCode s;
    std::cout<<s.isMatch(str, parttern)<<std::endl;
    return 0;
}

