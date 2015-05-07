#include<iostream>
#include<cassert>
#include<cmath>
#include<bitset>
#include<functional>

class Solution
{
public:
    int fast_power(int a, int b)
    {
        int d = 1;
        std::bitset<sizeof(b)*8> binary(b);
        int k = get_msb(b);

        for(int i=k; i>=0; --i)
        {
            d = d * d;
            if(binary.test(k))
            {
                d = d * a;
            }
        }
        return d;
    }

    int count_primes(int n, std::function<bool(int)> predicate)
    {
        assert(n>=2);
        int count_of_primes = 1;
        for(int i=3; i<n; i+=2)
        {
            if(predicate(i))
            {
                ++count_of_primes;
            }
        }
        return count_of_primes;
    }

    bool be_prime(int n)
    {
        if(modular_exponentiation(2, n-1, n) != 1)
        {
            return false;
        }
        return be_prime_base(n);
    }

    bool be_prime_base(int n)
    {
        int s_root = static_cast<int>(sqrt(n));
        int i = (n % 2 == 0) ? 2 : 3;
        for(; i<=s_root; i+=2)
        {
            if((n%i) == 0)
            {
                return false;
            }
        }
        return true;
    }

    int modular_exponentiation(int a, int b, int n)
    {
        int d = 1;
        std::bitset<sizeof(b)*8> binary(b);
        int k = get_msb(b);

        for(int i=k; i>=0; --i)
        {
            d = (d * d) % n;
            if(binary.test(i))
            {
                d = (d * a) % n;
            }
        }
        return d;
    }

    int get_msb(int val)
    {
        std::bitset<sizeof(int)*8> binary(val);
        for(int i=sizeof(int)*8-1; i>=0; --i)
        {
            if(binary.test(i))
                return i;
        }
        return -1; //all zero
    }
};

int main()
{
    Solution s;
    int n = 1500000;
    std::cout<<"count: "<<s.count_primes(n
            , std::bind(&Solution::be_prime
                , &s, std::placeholders::_1))<<std::endl;

    for(int i=2; i<1500000; i++)
        std::cout<<s.be_prime(i)<<" "<<s.be_prime_base(i)<<std::endl;
}

