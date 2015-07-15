#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

*/

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        last = false;
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }

    TrieNode* child[26];
    bool last;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* cur = root;
        for(int i=0; i<s.length(); i++)
        {
            char c = s[i];
            int val = c - 'a';
            //cout<<"debug -1, val is "<<val<<endl;

            if(cur->child[val] == NULL)
            {
                //cout<<"debug 0, val is "<<val<<endl;
                cur->child[val] = new TrieNode();
            }


            cur = cur->child[val];

        }
        cur->last = true;

    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* cur = root;
        //cout<<"debug 1"<<endl;
        for(int i=0; i<key.length(); i++)
        {
            int val = key[i] - 'a';
            //cout<<"debug 2, val is"<< val <<endl;
            if(cur && cur->child[val] != NULL)
                cur = cur->child[val];
            else
                return false;
        }
        //cout<<"debug 4"<<endl;
        //assert(cur!=NULL);

        if(cur->last == true)
            return true;

        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i=0; i<prefix.length(); i++)
        {
            int val = prefix[i] - 'a';
            if(cur && cur->child[val] != NULL)
                cur = cur->child[val];
            else
                return false;
        }

        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");



int main()
{
    Trie trie;
    trie.insert("abcd");
    assert( trie.search("abcd") );
    assert( trie.startsWith("ab") );
    trie.insert("ab"); // jima1, this is a whole word
    assert( trie.search("ab") );
    return 1;
}

