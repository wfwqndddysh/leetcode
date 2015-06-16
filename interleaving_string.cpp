#include<iostream>
#include<cassert>

class Solution
{
public:
    bool isInterleave(const std::string& s1
            , const std::string& s2
            , const std::string& s3)
    {
        return rec(true, s1, 0, s2, 0, s3, 0) || rec(false, s1, 0, s2, 0, s3, 0);
    }

private:
    bool rec(bool eat_s1
            , const std::string& s1, int i1
            , const std::string& s2, int i2
            , const std::string& s3, int i3)
    {
        if(eat_s1)
            return eat(!eat_s1, s1, i1, s2, i2, s3, i3);
        else
            return eat(!eat_s1, s2, i2, s1, i1, s3, i3);
    }

    bool eat(bool eatwho
            , const std::string& cur, int ci
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
            if(rec(eatwho, cur, ci, next, ni, dest, di))
                return true;
            ci--;
            di--;
        }

        return false;
    }
};

int main()
{
    Solution s;

    std::string s1("ab");
    std::string s2("ba");
    std::string s3("babc");
    
    std::cout<<s.isInterleave(s1, s2, s3)<<std::endl;
    return 0;
}

