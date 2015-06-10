#include<iostream>
#include<cassert>
#include<string>

class Solution
{
public:
    bool isPalindrome(const std::string& s)
    {
        int head=0;
        int tail=s.size()-1;

        for(; head<tail; ++head, --tail)
        {
            char n, p;
            get_next(s, head, n);
            get_prev(s, tail, p);

            if(head>=tail) return true;
            if(n!=p) return false;
        }
        return true;
    }
private:
    void get_next(const std::string& s, int& cur, char& c)
    {
        for(; cur<(int)s.length(); ++cur)
        {
            if(std::isalnum(s[cur]))
            {
                c=std::toupper(s[cur]);
                break;
            }
        }
    }

    void get_prev(const std::string& s, int& cur, char& c)
    {
        for(; cur>=0; --cur)
        {
            if(std::isalnum(s[cur]))
            {
                c=std::toupper(s[cur]);
                break;
            }
        }
    }
};

int main()
{
    Solution s;
    s.isPalindrome("1a2");
    std::cout<<std::endl;
    return 0;
}

