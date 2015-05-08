#include<vector>
#include<iostream>
#include<cassert>
#include<cstring>

struct TrieNode
{
    TrieNode()
        : is_end_(false)
    {
    }

    TrieNode(char c)
        : c_(c)
          , is_end_(false)
    {
    }

    std::vector<TrieNode*> children_;
    char c_;
    bool is_end_;
};

class Trie
{
public:
    Trie()
        : root_(new TrieNode())
    {}

    void insert(const std::string& s)
    {
        TrieNode* last_node = root_;
        auto last_itr = s.cbegin();

        if(find_last_char(&last_itr, s.cend(), root_, &last_node))
        {
            last_node->is_end_ = true;
            return;
        }

        for(; last_itr!=s.cend(); ++last_itr)
        {
            last_node->children_.push_back(new TrieNode(*last_itr));
            last_node = last_node->children_.back();
        }
        last_node->is_end_ = true;
    }

    bool startsWith(const std::string& s)
    {
        TrieNode* last_node = root_;
        auto last_itr = s.cbegin();

        return find_last_char(&last_itr, s.cend(), root_, &last_node);
    }

    bool search(const std::string& s)
    {
        TrieNode* last_node = root_;
        auto last_itr = s.cbegin();

        return find_last_char(&last_itr, s.cend(), root_, &last_node) ? last_node->is_end_ : false;
    }

    ~Trie()
    {
        cleanup(root_);
    }
private:
    using itr_type = std::string::const_iterator;

    bool find_last_char(itr_type* first
            , itr_type last
            , TrieNode* root
            , TrieNode** last_node)
    {
        for(auto n : root->children_)
        {
            if(n->c_==**first)
            {
                (*first)++;
                *last_node = n;

                if(*first==last)
                    return true;

                return find_last_char(first, last, n, last_node);
            }
        }
        return false;
    }

    void cleanup(TrieNode* root)
    {
        for(auto n : root->children_)
        {
            cleanup(n);
        }
        delete root;
    }

    TrieNode* root_;
};

struct TrieNodeFast
{
    TrieNodeFast()
        : is_end_(false)
    {
        memset(children_, '\0', sizeof(children_));
    }

    TrieNodeFast* children_[26];
    bool is_end_;
};

class TrieFast
{
public:
    TrieFast()
        : root_(new TrieNodeFast())
    {}

    void insert(const std::string& s)
    {
        TrieNodeFast* last_node = root_;
        auto last_itr = s.cbegin();

        if(find_last_char(&last_itr, s.cend(), root_, &last_node))
        {
            last_node->is_end_ = true;
            return;
        }

        for(; last_itr!=s.cend(); ++last_itr)
        {
            TrieNodeFast* node = new TrieNodeFast();
            last_node->children_[*last_itr-'a'] = node;
            last_node = node;
        }
        last_node->is_end_ = true;
    }

    bool startsWith(const std::string& s)
    {
        TrieNodeFast* last_node = root_;
        auto last_itr = s.cbegin();

        return find_last_char(&last_itr, s.cend(), root_, &last_node);
    }

    bool search(const std::string& s)
    {
        TrieNodeFast* last_node = root_;
        auto last_itr = s.cbegin();

        return find_last_char(&last_itr, s.cend(), root_, &last_node) ? last_node->is_end_ : false;
    }

    ~TrieFast()
    {
        cleanup(root_);
    }
private:
    using itr_type = std::string::const_iterator;

    bool find_last_char(itr_type* first
            , itr_type last
            , TrieNodeFast* root
            , TrieNodeFast** last_node)
    {
        auto cur = root->children_[**first-'a'];

        if(!cur)
            return false;

        (*first)++;
        *last_node = cur;

        if(*first==last)
            return true;

        return find_last_char(first, last, cur, last_node);
    }

    void cleanup(TrieNodeFast* root)
    {
        for(auto n : root->children_)
        {
            if(n)
            {
                cleanup(n);
            }
        }
        delete root;
    }

    TrieNodeFast* root_;
};

int main()
{
    Trie tree;

    tree.insert("a");
    tree.insert("ab");
    tree.insert("abc");
    tree.insert("abde");
    tree.insert("abcde");

    assert(tree.search("a"));
    assert(tree.search("ab"));
    assert(tree.search("abc"));
    assert(tree.search("abde"));
    assert(tree.search("abcde"));
    assert(!tree.search("abcd"));

    return 0;
}

