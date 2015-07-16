#include<iostream>
#include<cassert>

class Solution
{
public:
    int computeArea(int a, int b, int c, int d, int e, int f, int g, int h)
    {
        //(a,b),(c,d)
        //(e,f),(g,h)

        int area1=(c-a)*(d-b);
        int area2=(g-e)*(h-f);

        if(a>=g || e>=c || b>=h || f>=d ) return area1+area2;

        int x=std::min(c, g)-std::max(a, e);
        int y=std::min(d, h)-std::max(b, f);

        return area1+area2-x*y;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

