#include<vector>
#include<iostream>

struct TrieNode
{
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
        TrieNode* last_node = nullptr;
        auto last_itr = s.cbegin();

        if(find_last_char(&last_itr, s.cend(), root_, &last_node))
        {
            last_node->is_end_ = true;
        }

        TrieNode* root = last_node ? last_node : root_;
        ++last_itr;
        for(; last_itr!=s.cend(); ++last_itr)
        {
            root->children_.push_back(new TrieNode());
            root = root->children_.back();
        }
        root->children_.back()->is_end_ = true;
    }

    bool startWith(const std::string& s)
    {
        for(auto n : root_->children_)
        {
            if(search_internal(s.cbegin(), s.cend(), n))
                return true;
        }
        return false;
    }

    bool search(const std::string& s)
    {
        for(auto n : root_->children_)
        {
            if(search_internal(s.cbegin(), s.cend(), n))
                return true;
        }
        return false;
    }

    ~Trie()
    {
        delete root_;
    }
private:
    using itr_type = std::string::const_iterator;

    bool start_with_internal(itr_type first, itr_type last, TrieNode* root)
    {
        if(first==last)
            return true;

        if(root->c_!=*first)
            return false;

        for(auto n : root->children_)
        {
            if(start_with_internal(++first, last, n))
                return true;
        }
        return false;
    }

    bool search_internal(itr_type first, itr_type last, TrieNode* root)
    {
        if(root->c_!= *first)
            return false;

        if(++first==last)
            return root->is_end_;

        for(auto n : root->children_)
        {
            if(search_internal(++first, last, n))
                return true;
        }
        return false;
    }

    bool find_last_char(itr_type* first
            , itr_type last
            , TrieNode* root
            , TrieNode** last_char)
    {
        if(*first==last)
            return true;

        if(root->c_!= **first)
            return false;

        *last_char = root;

        for(auto n : root->children_)
        {
            *first = (*first)++;
            if(find_last_char(first, last, n, last_char))
                return true;
        }
        return false;
    }

    TrieNode* root_;
};

int main()
{
    return 0;
}

