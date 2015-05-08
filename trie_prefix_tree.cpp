#include<iostream>

struct TrieNode
{
};

class Trie
{
public:
    Trie()
        : root_(new TrieNode())
    {}

    void insert(const std::string& s)
    {
    }

    bool search(const std::string& s)
    {
        return false;
    }

    bool startWith(const std::string& s)
    {
        return false;
    }

    ~Trie()
    {
        delete root_;
    }
private:
    TrieNode* root_;
};

int main()
{
    return 0;
}

