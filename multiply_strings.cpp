#include<iostream>
#include<cassert>
#include<vector>
#include<string>

class Solution
{
public:
    std::string multiply(std::string num1, std::string num2)
    {
        std::string result;
        
        int sz_1 = num1.size();
        int sz_2 = num2.size();

        for(int i=sz_2-1; i>=0; --i)
        {
            std::string tmp;
            int high = 0;
            int j=sz_1-1;
            for(; j>=0; --j)
            {
                int multi = (num1[j]-'0')*(num2[i]-'0') + high;
                int low = multi%10;
                high = multi/10;

                if(tmp.empty())
                {
                    tmp.insert(tmp.begin(), low+'0');
                }
                else
                {
                    tmp[0]=low+'0';
                }
                tmp.insert(tmp.begin(), high+'0');
            }

            if(result.empty()) result=tmp;
            else
            {
                high = 0;
                int n=tmp.size()-1;
                for(int m=result.size()-sz_2+i; m>=0 && n>=0; --m, --n)
                {
                    int sum = (result[m]-'0'+tmp[n]-'0'+high);
                    high = sum/10;
                    result[m] = sum%10+'0';
                }

                for(; n>=0; --n)
                {
                    int sum = (tmp[n]-'0'+high);
                    high = sum/10;
                    result.insert(result.begin(), sum%10+'0');
                }
            }
        }

        for(; result.size()>1 && result[0]=='0'; )
            result.erase(result.begin());

        return result;
    }
};

int main()
{
    Solution s;
    /*
    std::string num1("0");
    std::string num2("0");
    */

    std::string num1("9");
    std::string num2("99");

    /*
    std::string num1("98");
    std::string num2("9");
    */

    /*
    std::string num1("512621602792789759");
    std::string num2("73487879881634");
    */

    std::cout<<s.multiply(num1, num2)<<std::endl;
    return 0;
}

