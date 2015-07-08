#include<iostream>
#include<cassert>
#include<vector>

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

