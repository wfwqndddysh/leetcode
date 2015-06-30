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

/*
我们来看一个例子，s="accbcbccx", p="a*b*d"，按解法二第一个*号其实是匹配了cc，即accb和a*b匹配了，
剩下的cbccx交给*d去匹配，试想如果cbccx和*d匹配失败了，我们回溯到上一个*号去匹配是否能够成功呢？
还是不能！因为*是可以匹配任意长度的，就算回到上一次的*号位置，让accbcb去和a*b匹配了，
剩下的ccx和*d还是不能匹配，因为其实第二个*既可以匹配ccx也可以匹配cbccx，
即是说后面的*号可以代替前面的*号的作用。总结一下，我们得出结论，在遇到*好不匹配时，
我们直接回到上一次开始比较的位置的后一个位置开始比较就可以了，如果能匹配必然能找到匹配，
如果不能匹配，那么再回溯也是没用的。而这也是解法三比解法二除了递归开销以外更节省时间的地方。
*/

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

