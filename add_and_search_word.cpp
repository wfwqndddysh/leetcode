#include<iostream>
#include<cassert>
#include<string>
#include<cstring>

class WordDictionary
{
public:
    // Adds a word into the data structure.
    void addWord(std::string word)
    {
        auto node=&root_;
        for(char c : word)
        {
            node=node->find(c) ? node->find(c) : node->insert(c);
        }
        node->set_end();
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(std::string word)
    {
        return rec_search(word, 0, &root_);
    }
    
private:
    struct TrieNode
    {
        TrieNode() : is_end_(false)
        {
            memset(children_, 0, sizeof(children_));
        }

        bool is_end() const
        {
            return is_end_;
        }

        void set_end()
        {
            is_end_=true;
        }

        TrieNode* find(char letter) const
        {
            return children_[letter-'a'];
        }

        TrieNode* insert(char letter)
        {
            children_[letter-'a']=new TrieNode();
            //std::cout<<children_[letter-'a']<<std::endl;
            return children_[letter-'a'];
        }

        TrieNode* children_[26];
        bool is_end_;
    };

    bool rec_search(const std::string& word, int cur, TrieNode* node)
    {
        int sz=word.size();
        if(cur==sz && node->is_end())
        {
            return true;
        }
        else if(cur<sz)
        {
            if(word[cur]=='.')
            {
                bool found=false;
                for(int i=0; i<26; ++i)
                {
                    if(node->children_[i])
                    {
                        found=rec_search(word, cur+1, node->children_[i]);
                        if(found) return found;
                    }
                }
                return false;
            }
            else
            {
                node=node->find(word[cur]);
                if(!node) return false;
                return rec_search(word, cur+1, node);
            }
        }

        return false;
    }



    TrieNode root_;
};

int main()
{
    std::cout<<std::endl;
    return 0;
}

