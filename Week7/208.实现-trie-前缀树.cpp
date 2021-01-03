/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
struct TrieNode {
    map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        if (word.length() == 0) {
            return;
        }
        
        TrieNode* currentNode = root;
        for (int i=0; i<word.length(); i++) {
            
            if (currentNode->children.find(word[i]) == currentNode->children.end()) {
                currentNode->children[word[i]] = new TrieNode();
            }
            currentNode = currentNode->children[word[i]];
        }
        currentNode->isEnd = true;

    }
    
    bool find(string word, bool isPrefix) {
        if (word.length() == 0) {
            return false;
        }
        TrieNode* currentNode = root;
        for (int i=0; i<word.length(); i++) {
            
            if (currentNode->children.find(word[i]) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[word[i]];
        }
        
        if (isPrefix) {
            return true;
        }
        else {
            return currentNode->isEnd;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, false);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

