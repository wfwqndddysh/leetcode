#include<iostream>
#include<cassert>
#include<vector>
#include<string>
#include<map>
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
    std::vector<std::string> repeatedDnaSequences_map(const std::string& s)
    {
        std::vector<std::string> res;
        std::map<std::string, int> s2count;

        if(s.length()<10)
            return res;

        for(size_t i=0; i<s.length()-9; ++i)
        {
            const std::string& subs = s.substr(i, 10);
            if(s2count.find(subs)!=s2count.cend())
            {
                res.push_back(std::move(subs));
            }
            else
            {
                s2count.insert(std::make_pair(subs, 1));
            }
        }
        return res;
    }

    std::vector<std::string> findRepeatedDnaSequences(const std::string& s)
    {
        std::vector<std::string> res;
        int8_t flags[131072] = {0};

        for(size_t i=0; i+9<s.length(); ++i)
        {
            const std::string& subs = s.substr(i, 10);
            size_t index = get_index(subs);

            if(!bit_test(flags, index))
            {
                res.push_back(subs);
                bit_set(flags, index);
            }
        }
        return res;
    }
private:
    size_t get_index(const std::string& s)
    {
        size_t index = 0;
        for(size_t i=0; i<s.length(); ++i)
        {
            if(s[i]=='C')
            {
                index += four_power[i];
            }
            else if(s[i]=='G')
            {
                index += four_power[i] * 2;
            }
            else if(s[i]=='T')
            {
                index += four_power[i] * 3;
            }
        }
        return index;
    }

    std::vector<size_t> four_power{1, 4, 14, 64, 256, 1024, 4096, 16384, 65536, 262144};
};

int main()
{
    Solution s;
    for(const auto& n : s.findRepeatedDnaSequences("AAAAAAAAAAAA"))
    {
        std::cout<<n<<std::endl;
    }
    return 0;
}

