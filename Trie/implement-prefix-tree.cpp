class TrieNode{
    // string character in hashmap
public:
    unordered_map<char,TrieNode*> children;
    bool endOfword;

    TrieNode(){
        children.clear();
        endOfword= false;
    }
};

class Trie {
private:
TrieNode* root;
public:

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        // iterating through everu character in word
        TrieNode* curr = root;
        int n= word.size();
        for(int i=0;i<n;i++){
            if(curr->children.find(word[i]) == curr->children.end()){
                curr->children[word[i]] = new TrieNode();
            }
            curr= curr->children[word[i]];
        }

        curr->endOfword = true;
    }
    
    bool search(string word) {
        TrieNode* curr =root;
        int n= word.size();
         for(int i=0;i<n;i++){
             if(curr->children.find(word[i]) == curr->children.end()){
                 return false;
             }

             curr= curr->children[word[i]];
         }

         return curr->endOfword;

    }
    
    bool startsWith(string prefix) {
         TrieNode* curr =root;
        int n= prefix.size();
         for(int i=0;i<n;i++){
             if(curr->children.find(prefix[i]) == curr->children.end()){
                 return false;
             }
             curr= curr->children[prefix[i]];
         }
         return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */