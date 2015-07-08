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

            if(mod>=1 && mod<=3)
            {
                if(i==1) roman = mod==1 ? "I" : mod==2 ? "II" : "III" + roman;
                else if(i==2) roman = (mod==1 ? "X" : mod==2 ? "XX" : "XXX") + roman;
                else if(i==3) roman = (mod==1 ? "C" : mod==2 ? "CC" : "CCC") + roman;
                else roman = (mod==1 ? "M" : mod==2 ? "MM" : "MMM") + roman;
            }
            else if(mod==4)
            {
                if(i==1) roman = "IV" + roman;
                else if(i==2) roman = "XL" + roman;
                else roman = "CD" + roman;
            }
            else if(mod==5)
            {
                if(i==1) roman = "V" + roman;
                else if(i==2) roman = "L" + roman;
                else roman = "D" + roman;
            }
            else if(mod>=6 && mod<=8)
            {
                if(i==1) roman = (mod==6 ? "VI" : mod==7 ? "VII" : "VIII") + roman;
                else if(i==2) roman = (mod==6 ? "LX" : mod==7 ? "LXX" : "LXXX") + roman;
                else roman = (mod==6 ? "DC" : mod==7 ? "DCC" : "DCCC") + roman;
            }
            else if(mod==9)
            {
                if(i==1) roman = "IX" + roman;
                else if(i==2) roman = "XC" + roman;
                else roman = "CM" + roman;
            }
        }

        return roman;
    }
};

class SolutionLeetCode
{
    std::string intToRoman(int num)
    {
        std::string romanPieces[]={"","I","II","III","IV","V","VI","VII","VIII","IX",
                                   "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                                   "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                                   "","M","MM","MMM"};

        return romanPieces[num/1000+30]
            +romanPieces[(num/100)%10+20]
            +romanPieces[(num/10)%10+10]
            +romanPieces[num%10];
    }
};

int main()
{
    Solution s;
    //std::cout<<s.intToRoman(10)<<std::endl;
    std::cout<<s.intToRoman(90)<<std::endl;
    return 0;
}

