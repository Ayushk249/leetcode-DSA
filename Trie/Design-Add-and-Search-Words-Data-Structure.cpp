
class TrieNode{
public:
    unordered_map<char,TrieNode*> children;
    bool endOfWord;
    TrieNode(){
        endOfWord = false;
        children.clear();
    }
};


class WordDictionary {
private:
TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        TrieNode* dot = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(curr -> children.find(word[i]) == curr->children.end()){
                curr->children[word[i]] = new TrieNode();
            }

            curr=curr->children[word[i]];
        }

        curr->endOfWord = true;
    }

    // helper function for backtracking
    bool dfs (string word, TrieNode* child){
        TrieNode* curr = child;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(word[i]=='.'){
                for(auto itr = curr->children.begin();itr!=curr->children.end();itr++){
                    TrieNode* child = itr->second;
                    string remWord = word.substr(i+1,n-(i+1));
                    if(dfs(remWord,child)){
                        return true;
                    }
                }
                return false;

            }else{
                if(curr -> children.find(word[i]) == curr->children.end()){
                    return false;
                }
                curr= curr->children[word[i]];
            }
        }
        return curr->endOfWord;
    }


    bool search(string word) {
        return dfs(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */