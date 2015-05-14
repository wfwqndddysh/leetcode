#include<iostream>
#include<cassert>
#include<vector>
#include<string>
#include<map>
#include<cstring>

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

    //four base method 其实是挺容易理解的
    std::vector<std::string> findRepeatedDnaSequences_four_base(const std::string& s)
    {
        std::vector<std::string> res;
        int8_t flags[262144*4] = {0};

        for(size_t i=0; i+9<s.length(); ++i)
        {
            const std::string& subs = s.substr(i, 10);
            size_t index = get_index(subs);
            if(flags[index]==0)
            {
                flags[index]=1;
            }
            else if(flags[index]==1)
            {
                flags[index]=2;
                res.push_back(subs);
            }
        }
        return res;
    }

    //string convert to int hash
    //A: 00
    //C: 01
    //G: 10
    //T: 11
    std::vector<std::string> findRepeatedDnaSequences(const std::string& s)
    {
        std::vector<std::string> res;
        if(s.length()<10)
            return res;

        int hashMap[1024*1024] = {0};
        size_t prev = get_hash(s.data(), 0, 10);
        hashMap[prev]++;
        for(size_t i=1; i+9<s.length(); ++i)
        {
            int hash_index = get_hash(prev, s[i+9]);
            if(hashMap[hash_index]++==1)
            {
                res.push_back(s.substr(i, 10));
            }
            prev = hash_index;
        }
        return res;
    }
private:
    size_t get_index(const std::string& s)
    {
        size_t index = 0;
        for(int i=s.length()-1; i>=0; --i)
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

    size_t get_hash(int prev, char c)
    {
        int c2int[26] = {0};
        c2int['A'-'A'] = 0;
        c2int['C'-'A'] = 1;
        c2int['G'-'A'] = 2;
        c2int['T'-'A'] = 3;
        return ((prev & 0x3FFFF) << 2) | c2int[c-'A'];
    }

    size_t get_hash(const char* s, int begin, int end)
    {
        int c2int[26] = {0};
        c2int['A'-'A'] = 0;
        c2int['C'-'A'] = 1;
        c2int['G'-'A'] = 2;
        c2int['T'-'A'] = 3;

        int hash_index = 0;
        for(;begin<end;++begin)
        {
            hash_index = (hash_index << 2) | c2int[s[begin]-'A'];
        }
        return hash_index;
    }

    std::vector<size_t> four_power{1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144};
};

int main()
{
    srand(time(nullptr));
    std::string dna;

    for(int cnt=0; cnt<10000; cnt++)
    {
        int r = rand();
        char c = 'A';
        int m = (r % 4);
        if(m==1)
            c = 'C';
        else if(m==2)
            c = 'G';
        else if(m==3)
            c = 'T';

        dna.push_back(c);
    }
    //std::cout<<dna<<std::endl;
    //dna = "CCAAGTCTAAAAGAATGGGCAGAGTTGCTCTGCACGTTCCGGATACGATAAGAAGACTCCGCCGGGCACCGCCAGTCCCTCGCAGGGGGACACATTGGAATCGGATAATCGATCACTCCGCGCCACCCCGGGTTACGCACCTCACGTTGAGTGAGGAGATGGTGACATTTCGGCACCTATAGGCACGCTCTACCGGAACAGCATCTGTATCAGATGGCAATTCGATGGTATCTTGCGTGAATCAGGAAGTTTTATGTGGCTTCCGGATGACGCGAGATTTTGCGTGAGGTGAGCGGTTGCGTTACCGGTTAGTAGCCCTTAGTAGTTGAAGACAGGCGAGCAGGTGCAGCTGTCCACACGGTATAGGGCAATCAACTTCCATAAAGCATATGTTGTGTAACACCTGCCACCCCTTGTCACAGGTTTCACCAAGACCACATCGTGCTAAAGTTAAACAACATTCGTAAAAGTGCAGAAATTGAAGTATTTGATCTGAGATTACGTTTCAATCTGGAATCCGAAGCTATAGGAGAATGTTGGACCATACGGTGAGTAGAATCGCCACTCACGTTTCGGTACTAGCACATTAGTACGGATCCCGATCGGGGTGGTGGGGCGTTCTTCATGTATACCATTGCGACGGAGTCTGGCTAAACCTTTAGGCAGGTCGCAAGGCAGAATCATGAGCACAATCAGGGTGGCCTGGATCCGTCATGGAGGAATCGGGTCTTCCCGTTTGAGGGGGCGGACTTCGCGGCGCACGTCAGGACACCAAAGGCTCTAGTACCCTCCTATCGAAACTCTTTAGCGAGTTTTGTCCAGCTAGCTTCATCTAACAGGCTCAAAAGTCATAAGAAGGCTCACTTTAAGTAAAAAGTCAGGCGCAAAGTCTAGTGGCGCATTTGATACGTTCCCAGGGCACACATGCACCCCTCTGCAACATTTCAGGCCGCAATTACACTGTAGCTCACCGGGGTCGAAATAGTTAACTCAAGTTTCCGGTCCCTTCCCCACAAAGATCTGTATATGAACCATCAAGACGTGGCTAATAATTATATCTCCGGCCCCTGCCACAGGAGAGAGGGAGCCGGAATGACCGTAATTAGCTCATAAAACTTACCAGCTTATAGGAAGTCGGCTTCTTTGATGACTACGAAATGGTAGGGCGTTCGTTATGTGCTCTCGCGTTCAACATCCGGCGCGACCAATATGCCAACATTCGGAAGCGTGTGATAAATTGCTGAATCCATAGTCCCATAGTGGTTGATAGTTACTCCGGTTCTGAACTTGTGTAATAAATGCCAACATTCTCGTTACTCAGAACGACAGTCAAAGTGCGTGTCACGTTGGGCCTGGGGCACGTCGCTGGTATTCGGGTACTTTACTAATGAATAAGGATTGTGTTGTAGGCCCCTTAAAAACAGGGAATGGGCCGAATACATTTAGCTTGATTCCAGCGGTAGTACTTGGCGGAGTCATGTACCTTACCCGCGCATATAACTCCAGTCGGACATACGTTAGAATTTTGAAAAGGCTGGCGGGGACCGCGAGATGTCCGCCACCCATGTCGCGGCGTGAGGTGACATGACAGCCAGGCAGTTGGCTCGGTGTCCCAGGTGCACGGCCTCACTTAAACTAGCACCCGACGGATTCTTCATACCTGACGTGTGTATTTTTTGACTCTGAGGTTCTGAATAACATCCGTAGGCACATGTGAGAGCAGGGACGGTTCATCACCTATGGTCTCCAGGTACAGCCTACGTGGGGTAGGACCACAACACTCTGTGTGCCATACGGTCGGTCAAGACCTAATGGCGGGAAAAGTGGCTTTAGTCCCGTTGTACGAGGGAAATCAGTTTGGTTACGTGAAAAGTTAATGCTGCATCCAGTGACTACGATATTACCCGGCGAAACGAGATCGTAGTAGTTCTATGTCGGGCTGTCACCTAAGACACCATAAAAGGCGATTAAATATGGATGTGCGGAAGGGTGACTTCTACCCTCAAGACAACTGACTACCACCTTATACGCGCTTCATCGGGAGCTAGCGAGGCGCATCGCACAGTTACAAAGGGGTGTGGTAGGCACCCTGAACACAGAGAGTCACGCCGTGGGAAGACGACGGCGCCCGAACTGCTATCAGCTTCAAACTTCCAACGCCCATCGCGAGCGTACTGAGTTTTCACAGCGGGCTTCCACAAAGAAGTGGCCAGGCGACACCACATTACTGGGTCTGAGCCTCAGGCCAGGCGAAGTAATTGGTTTTGTGGGAATAGTGCACAAATGACCCATATGTGTTGTCAAGTCCCCTGCGACCGTTCGTCGGCGTACCCTTCGCTAATTTCCTAAGCACAATAATTGCAACCCCAAATGAGTCTCGTATTAGAGTAACGCAGAGTTAGGCTCCCCGAAAACGCTAGTCCGGAGCTTGGGATAAAAATAATGATGTAGGGCGGGACCCCGTACTTTCGCATAACAGGGTTTTTGTCGGTTGGCTTGTAAATGCAACTTGGGTTCCACAATCCCACTGGACAAGACAGGAAGGTGAAGAGGGAGCCGATTAAACCCAACTCAACTAGAACTTAGATCTTTCATTCACATCGTGTCAGTACAAATTTGAAAGAGAAGTAGGTACATGGGAGGAACGGGTTACGCCGAGTCTGATATTCTGTGGGAACTCCGTCTGGTCGCAGAGTTACGCCATCACAGCATTGGCTGAGTATCCAATTTGCCTATCACGCAACTACCATTTGCCGATAGCGGACCGACCCTATTTGAGCTATGGTATGTTCACGAATACAACTACGTCTGACAAGACGAGATCCTAAGCACAACTCCTACGATTCCGGACGTCTGGCCCTTGGAGCACTAATCCCTGGGGAATGTCACCAGAGATGTTTACGGCATGAAGAATGGAGGTCACAATTATTGAGAGACGGCGGTATGCACCATATCCAGGGTGCAGTGAGACGATAGACGTAGGGGAGCGGAGCGTCGAGGTGTCTCTGCCAAAGGGCCCCAATGATCCTGAATGGTGTAATCCGGAGACTCGATGGTATCCGCCGCAACGGTTCACTCCGCGTATGGCAGTTGGCTACGTGGTCGCGAGGACAGCTGTACGTTAAGCTAAACGATCCCTTAGCCTCTCGCAGATCGAAGTGCTAATAGTCCTGTCGCAGCCAGGATTGCGAAACTACGACTCAGGGGTAATCGCGGATAGCCTGATTTCATCCGAAAGACCCACACTATAGTCTGTGGTCGGTCCCAGGCGGTTCACGCCACCGGCGACATCGGCAAGTCTACAGGGGTTGGGCCAATTTCCGATAGGATCTCGGAAATGGTATCTCCGACCAGCGCAAACGCGCCACCCTGCGAGTCCGGAGTTTGCTACTCTTCAAATGAACCGATCGCGTCGTCGTTGAAACCGTGAGAGCAACCAGAATTACATTAAGCTCATCGGGATATTGATCCAATTGGGTAAATGTCAACGCTTCAATTTTTGCCGTGTCGCAACCTCCGGATAAACTTAGTACAGATCTTTTGTCGTAGAACGTTGTGGAAGCAGCAGGGAGACCCTGTACTTTCGTCACCTATCAACGTTTCCACCTCTGGTGATGTAAAAGCACGCAACCTACTCCGATACCAATCTGAGTTATGCTGTAAATTATTGGACGCCAATGGGATAAATGGGTAACGTGACCGATACGAAGCTGGCCCTTTCTCCCTCCAGTACCGATGGAATCTAGTACTTTTATAATGATTGGCACGGACGCACCGGTGTGGTTGACCGATTTGGCGGTAACATTGCGGGTTAGGGGGTTAATATATAACGCCTTCACCGATCGCACTACACGCAGATCGGAGGCTCCACTCAGACGTAGAATTTAAACAGAGATGGCTAGCGAAACTCCAAGCAGACGGCAAGGCTGTTCACCAGGAAGCCCCCTTCAAGATTCGTATTCAGGTATTGAGCAAACATCACTGACATTATTTTTGGATTAGCATAGGAAATATATACCGACTCGCGGTGGAGGTCAATGTCAACAGTGCGTGTTTTTAATGTCTGAACAATTTGCCTCCAAAATCTTGTTCGTTATCTCCCGATCAATTACCGCTAGCATTCGGGCATCTTGCGACCCAAGATTGAGATGAGGTGTGAACACTATCTGCACTGACAGCGGTCATAGCGGCGTAAAAATCGTGCGGAGGGAACCTTCACTCATGAGCAGCGGTGTAAAACCCTATGAGACAATTCGCTCCGATGGATAGTGTTGCGCTGACGTCCCACCGGACCAGCAGATATTCAACTCGAGAACATCTTAAAGTTTCCATCTAGGGCGGACCCTCAGGCTTTGCACGTCGGGGCTTAATGGTAATATGAGGTACGATTTAGTCGAATGGTTAAAGACCGTGACCGTGATATGCGCAACAATTCCCTCTGATACCCACTCATCGGGGTGGATTCTGAACACAGTCTGCATAAGTCTCAACCCATGGACGGGGAACTGTTACGAAATATGCAGGGGTCCGATTAGTCCCAGGGTGAGTCTTCCCTTACCGATCTCCACCGTGTTCCATGAGTCGCCGGTGTTTGATTACTGTCTATAGGCCTTACCGTCGTTACTGAGATTTATGGGCGGGGACGTTCGACTGCACTTTCAATTGGCAGAATTCCGTTAAATAAGGACGCAGTTGTCCGCGCACTTCATACCGTTGAGAAAGCAATACATTTTCTTGACACTCCCGGCATGTCGTCATATAGTACCGTCTAGCATTCTGCTAGCTCAAAAGCTCTCTGGCACCGGCATGTGTGACGTATCGAAAGAACAGCACTACAGCAGGCGAGTAGCTCCGGGCTACTTTGTTGCACAGCTACATGCAGTGGTGGTAACTTCGATTGATCCCGGCTCTAGGACTGAGCTTTAGCGAGTCCCTACCCGGCAAGTTCGCCTGATCCTGTCTTGGATGAACTTGGGCGGGCTCTGGCGGGTTGTTAGATC";
    dna = "AAAAAAAAAA";

    Solution s;
    for(const auto& n : s.findRepeatedDnaSequences(dna))
    {
        std::cout<<n<<std::endl;
    }
    return 0;
}

