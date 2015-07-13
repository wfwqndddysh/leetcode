#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int countDigitOne(int n)
    {
        if(n<1) return 0;
        if(n<9) return 1;

        int res=0;
        std::vector<int> table(12, 1);

        int m=n%10;
        int tn=n/10;
        int low=m;
        res=m>0 ? 1 : 0;

        for(int i=2, base=1; tn!=0; i++, tn /= 10)
        {
            base = base*10;
            table[i]=10*table[i-1]+base;

            m=tn%10;

            if(m!=0)
            {
                res += m*table[i-1] + std::min(m*base+low-base+1, base);
            }

            low = m*base+low;
        }

        return res;
    }
};

/*
intuitive: 每10个数, 有一个个位是1, 每100个数, 有10个十位是1, 每1000个数, 有100个百位是1.  做一个循环, 每次计算单个位上1得总个数(个位,十位, 百位). 

例子:

以算百位上1为例子:   假设百位上是0, 1, 和 >=2 三种情况:

case 1: n=3141092, a= 31410, b=92. 计算百位上1的个数应该为 3141 *100 次.

case 2: n=3141192, a= 31411, b=92. 计算百位上1的个数应该为 3141 *100 + (92+1) 次.

case 3: n=3141592, a= 31415, b=92. 计算百位上1的个数应该为 (3141+1) *100 次.

以上三种情况可以用 一个公式概括:

(a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
*/

class SolutionLeetCode
{
public:
    int countDigitOne(int n)
    {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10)
        {
            int a = n/m;
            int b = n%m;
            ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
        }
        return ones;
    }
};

/*
class SolutionLeetCode2
{
public:
    int countDigitOne(int n)
    {
        int res = 0, a = 1, b = 1;
        while (n > 0)
        {
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};
*/

int main()
{
    SolutionLeetCode s;
    std::cout<<s.countDigitOne(111)<<std::endl;
    //std::cout<<s.countDigitOne(113)<<std::endl;
    //std::cout<<s.countDigitOne(100)<<std::endl;
    //std::cout<<s.countDigitOne(20)<<std::endl;
    //std::cout<<s.countDigitOne(3141592)<<std::endl;
    return 0;
}

