#include<iostream>
#include<cassert>
#include<string>

class Solution
{
public:
    std::string intToRoman(int num)
    {
        std::string roman;

        for(int i=1; num>0; ++i, num/=10)
        {
            int mod=num%10;

            if(mod>0 && mod<3)
            {
                if(i==1)
                {
                    roman = mod==1 ? "I" : mod==2 ? "II" : "III";
                }
                else if(i==2)
                {
                    roman = mod==1 ? "XI" : mod==2 ? "XII" : "XIII";
                }
                else if(i==3)
                {
                    roman = mod==1 ? "CX" : mod==2 ? "CXX" : "CXXX";
                }
                else
                {
                    roman = mod==1 ? "MC" : mod==2 ? "MCC" : "MCCC";
                }
            }
            else if(mod==4)
            {
            }
            else if(mod==5)
            {
            }
            else
            {
            }

        }
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

