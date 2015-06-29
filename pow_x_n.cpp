#include<iostream>
#include<cassert>

class Solution
{
public:
    double myPow(double x, int n)
    {
        return pow(x, n);
    }

private:
    double power(double x, int n)
    {
        if (n == 0)
            return 1;
        double v = power(x, n / 2);
        if (n % 2 == 0)
            return v * v;
        else
            return v * v * x;
    }

    double pow(double x, int n)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 0)
            return 1.0 / power(x, -n);
        else
            return power(x, n);
    }
};

class SolutionLeetCode
{
public:
    double myPow(double x, int n)
    {
        double left = x;
        double right = 1;

        if (n<0) return 1/(x*myPow(x,-n-1)); // Avoid binary overflow!!!!

        if (!n) return 1;

        while (n>1)
        {
            if ((n&1)==1) right *= left;
            left = left * left;
            n = n>>1;
        }

        return left * right;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

