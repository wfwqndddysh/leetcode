#include<iostream>
#include<cassert>

class Solution
{
public:
    std::string convertToTitle(int n)
    {
        return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char) ((n - 1) % 26 + 'A');
    }
};

int main()
{
}

