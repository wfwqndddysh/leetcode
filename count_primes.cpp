#include<iostream>
#include<cassert>
#include<cmath>
#include<bitset>
#include<functional>
#include<cstring>

const static int8_t shift = 3;
const static int8_t mask = 7;

inline void bit_reset(int8_t* m, size_t l)
{
    m[l>>shift] &= ~(1 << (l&mask));
}

inline bool bit_test(int8_t* m, size_t l)
{
    return m[l>>shift] & (1 << (l&mask));
}

inline void bit_set(int8_t* m, size_t l)
{
    m[l>>shift] |= (1 << (l&mask));
}

class Solution
{
public:
    int count_primes(int n)
    {
        int byte_len =(n>>3)+1;
        int8_t* table = new int8_t[byte_len];
        memset(table, '\0', byte_len);

        auto bit_set = [](int8_t* t, size_t l)->void
        {
            t[l>>3] |= (1 << (l&7));
        };

        auto bit_test = [](int8_t* t, size_t l)->bool
        {
            return t[l>>3] & (1 << (l&7));
        };

        for(int i=2; i<n; ++i)
        {
            if(!bit_test(table, i))
            {
                for(int j=i + i; j<n; j+=i)
                {
                    bit_set(table, j);
                }
            }
        }

        int count_of_primes = 0;
        for(int i=2; i<n; ++i)
        {
            if(!bit_test(table, i))
            {
                ++count_of_primes;
            }
        }
        delete[] table;
        return count_of_primes;
    }
};

int main()
{
    Solution s;
    int n = 1500000;
    std::cout<<s.count_primes(n)<<std::endl;
}

