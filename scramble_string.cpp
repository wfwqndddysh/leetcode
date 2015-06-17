#include<iostream>
#include<cassert>
#include<string>
#include<algorithm>

class SolutionRec
{
public:
    bool isScramble(std::string s1, std::string s2)
    {
        if (s1.size() != s2.size())
            return false;

        if (s1.size() == 1)
            return s1 == s2;

        std::string st1 = s1, st2 = s2;
        sort(st1.begin(), st1.end());
        sort(st2.begin(), st2.end());

        if(st1!=st2) return false;

        int len = s1.size();
        bool ret = false;
        for (int i = 1; i < len && !ret; ++i)
        {
            std::string s11 = s1.substr(0, i);
            std::string s12 = s1.substr(i, len-i);
            std::string s21 = s2.substr(0, i);
            std::string s22 = s2.substr(i, len-1);

            ret = isScramble(s11, s21) && isScramble(s12, s22);

            if (!ret) {
                s21 = s2.substr(len-i, i);
                s22 = s2.substr(0, len-i);
                ret = isScramble(s11, s21) && isScramble(s12, s22);
            }
        }
        return ret;
    }
};

class SolutionDP
{
public:
    bool isScramble(const std::string& s1, const std::string& s2)
    {
        auto len=s1.length();
        if(len!=s2.length()) return false;

        std::vector<std::vector<std::vector<bool>>> dp(len, std::vector<std::vector<bool>>(len, std::vector<bool>(len, false)));

        for(size_t l=1; l<=len; ++l)
        {
            for(size_t i=0; i<=len-l; ++i)
            {
                for(size_t j=0; j<=len-l; ++j)
                {
                    if(l==1)
                    {
                        dp[i][j][0] = s1[i]==s2[j];
                    }
                    else
                    {
                        for(size_t k=1; k<l; ++k)
                        {
                            if((dp[i][j][k-1] && dp[i+k][j+k][l-k-1]) || (dp[i][j+l-k][k-1] && dp[i+k][j][l-k-1]))
                            {
                                dp[i][j][l-1] = true;
                                break;
                            }

                            /*
                            bool l_l = dp[i][j][k-1];
                            bool r_r = dp[i+k][j+k][l-k-1];
                            bool l_l_r_r = l_l && r_r;

                            if(l_l_r_r)
                            {
                                dp[i][j][l-1] = true;
                                break;
                            }

                            bool l_r = dp[i][j+l-k][k-1];
                            bool r_l = dp[i+k][j][l-k-1];
                            bool l_r_r_l = l_r && r_l;
                            dp[i][j][l-1] = l_r_r_l;
                            */
                        }
                    }
                }
            }
        }
        return dp[0][0][len-1];
    }
};

class Solution
{
    public:
        bool isScramble(std::string s1, std::string s2)
        {
            int n = s1.length();
            return judge(s1.c_str(), s2.c_str(), 0, n-1, 0, n-1);
        }

        bool judge(const char* s1, const char* s2,int a,int b,int u, int v)
        {
            if(b-a!=v-u) return false;
            if(b-a==0 && s1[a]==s2[u]) return true;

            int cnt[256]={0};
            for(int i=a;i<=b;++i)
            {
                cnt[s1[i]]++;
            }
            for(int i=u;i<=v;++i)
            {
                cnt[s2[i]]--;
            }
            for(int i=0;i<256;++i)
            {
                if(cnt[i]!=0) return false;
            }

            for(int i=a;i<b;++i)
            {
                if(judge(s1,s2,a,i,u,u+i-a) && judge(s1,s2,i+1,b,v-(b-i-1),v))
                {
                    return true;
                }
                if(judge(s1,s2,a,i,v-(i-a),v) && judge(s1,s2,i+1,b,u,u+b-(i+1)))
                {
                    return true;
                }
            }
            return false;
        }
};

int main()
{
    SolutionDP s;
    std::cout<<s.isScramble("a", "a")<<std::endl;
    return 0;
}

