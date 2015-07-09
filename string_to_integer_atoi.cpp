#include<iostream>
#include<cassert>
#include<string>
#include<climits>

class Solution
{
public:
    int myAtoi(std::string str)
    {
        if(str.empty()) return 0;

        int len=str.size();
        int64_t res=0;
        int sign=1;
        int base=10;
        int start=0;;

        while(start<len && (str[start]==' ' || str[start]=='\t'))
            start++;

        if(str[start]=='+')
        {
            sign=1;
            start++;
        }
        else if(str[start]=='-')
        {
            sign=-1;
            start++;
        }

        if(str[start]==0)
        {
            if(start+1<len && (str[start+1]=='x' || str[start+1]=='X'))
            {
                base=16;
                start += 2;
            }
            else
            {
                return 0;
            }
        }

        for(int i=start; i<len; ++i)
        {
            if(str[i]=='0' && res==0)
                continue;

            int cur_val=0;

            if(base==10)
            {
                if(str[i]>='0' && str[i]<='9')
                    cur_val=str[i]-'0';
                else
                    break;
            }
            else
            {
                if(str[i]>='0' && str[i]<='9')
                    cur_val=str[i]-'0';
                else if(str[i]>='a' && str[i]<='f')
                    cur_val=str[i]-'a'+10;
                else if(str[i]>='A' && str[i]<='F')
                    cur_val=str[i]-'A'+10;
                else
                    break;
            }
            res = res*base + cur_val;

            int64_t cur=res*sign;
            if(cur>INT_MAX) return INT_MAX;
            if(cur<INT_MIN) return INT_MIN;
        }

        return res*sign;
    }
};

int main()
{
    Solution s;
    //std::string str(" +004500");
    std::string str("9223372036854775809");

    std::cout<<s.myAtoi(str)<<std::endl;
    return 0;
}

