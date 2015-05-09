#include<cstdint>
#include<cstddef>

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

int get_lmb(int n)
{
    int lmb = -1;;
    while(n>0)
    {
        if(n & 1)
        {
            return ++lmb;
        }
        n = (n >> 1);
        lmb++;
    }
    return lmb;
}

int get_smb(int n)
{
    int smb = -1;
    while(n > 0)
    {
        n = (n >> 1);
        smb++;
    }
    return smb;
}

int main()
{
    return 0;
}

