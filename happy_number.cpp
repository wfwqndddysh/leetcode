#include<iostream>
#include<cassert>

class Solution
{
public:
    bool isHappy(int n)
    {
        int sum = 0;
        int sum_table[500] = {0};
        int cur = n;

        while(sum != 1)
        {
            sum = 0;
            while(cur>0)
            {
                int s = cur % 10;
                sum += s * s;
                cur = cur/10;
            }

            if(sum==1)
            {
                return true;
            }

            if(sum_table[sum]==sum)
                return false;

            cur = sum;
            sum_table[sum] = sum;
        }
    }
};

//下面是来自leetcode上高手的做法，唉
int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}

int main()
{
    Solution s;
    std::cout<<std::boolalpha<<s.isHappy(7)<<std::endl;;
    return 0;
}

