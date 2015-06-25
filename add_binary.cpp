#include<iostream>
#include<cassert>
#include<string>
#include<algorithm>

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        std::string c;
        
        int len_a=a.length();
        int len_b=b.length();

        int d=0;
        int i=len_a-1;
        int j=len_b-1;
        for(; i>=0 && j>=0; --i, --j)
        {
            int b1=a[i]-'0';
            int b2=b[j]-'0';
            add(b1, b2, d, c);
        }

        for(; i>=0; --i)
        {
            int b1=a[i]-'0';
            add(b1, 0, d, c);
        }

        for(; j>=0; --j)
        {
            int b2=b[j]-'0';
            add(0, b2, d, c);
        }

        if(d==1) c.push_back('1');
        std::reverse(c.begin(), c.end());

        return c;
    }

private:
    void add(int b1, int b2, int& d, std::string& c)
    {
        int sum = b1+b2+d;
        if(sum<2)
        {
            c.push_back('0'+sum);
            d=0;
        }
        else if(sum==2)
        {
            c.push_back('0');
            d=1;
        }
        else
        {
            c.push_back('1');
            d=1;
        }
    }
};

int main()
{
    Solution s;
    std::cout<<s.addBinary("1", "1")<<std::endl;
    return 0;
}

