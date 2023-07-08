// Getting TLE if searching for each word in the board using Backtracking

// class Solution {
// public:
//     bool dfs(int i,int j,vector<vector<char>>& board, int p,string word){
//         if(p== word.size()){
//             return true;
//         }

//         if(i<0 || j<0 || i > board.size()-1 || j> board[0].size()-1 || board[i][j] != word[p]){
//             return false;
//         }

//         board[i][j] = '@';

//         bool result = dfs(i+1,j,board,p+1,word) ||
//                       dfs(i-1,j,board,p+1,word) ||
//                        dfs(i,j+1,board,p+1,word) ||
//                         dfs(i,j-1,board,p+1,word);

//             board[i][j] = word[p];

//         return result;
//     }
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         int l = words.size();
//         int n = board.size();
//         int m = board[0].size();
//         vector<string> result;
//         for(int k =0;k<l;k++){
//            string word = words[k];
//             bool res= false;
//             for(int i=0;i<n;i++){
//                 for(int j=0;j<m;j++){
//                     res = dfs(i,j,board,0,word);
//                     if(res){
//                         result.push_back(word);
//                         break;
//                     }
//                 }
//                 if(res){
//                     break;
//                 }
//             }
//         }

//         return result;
//     }
// };



// using Trie data structure

class TrieNode{
public:
    unordered_map<char,TrieNode*> children;
    bool endOfWord;

    TrieNode(){
        children.clear();
        endOfWord = false;
    }
};

class Solution {
public:
    TrieNode* root;

    void dfs(int i,int j,vector<vector<char>>& board, TrieNode* child,string word, vector<string>&result, unordered_set<string> &track){
        TrieNode* curr = child; 
        
        if(child -> endOfWord){
            if(track.find(word)==track.end()){
                result.push_back(word);
                track.insert(word);
            }
            
        }
    // Not satisfying cases
    if(i<0 || j<0 || i > board.size()-1 || j> board[0].size()-1 || child->children.find(board[i][j]) == child->children.end()){
            return;
        }
        
        
        curr = curr-> children[board[i][j]];
        char s= board[i][j];
        word.push_back(s);
        board[i][j] = '@';

         dfs(i+1,j,board,curr,word,result,track);
        dfs(i-1,j,board,curr,word,result,track);
        dfs(i,j+1,board,curr,word,result,track);
        dfs(i,j-1,board,curr,word,result,track);

        board[i][j] = s;
        word.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int l = words.size();
        int n = board.size();
        int m = board[0].size();
        vector<string> result;
        root = new TrieNode();

        if(n==0 && m==0){
            return result;
        }
        
        // forming Trie prefix tree
        for(int k =0;k<l;k++){
           string word = words[k];
           TrieNode* curr = root;
           int len = word.size();
           for(int i=0;i<len;i++){
               if(curr -> children.find(word[i]) == curr -> children.end()){
                   curr-> children[word[i]] = new TrieNode();
               }
               curr = curr -> children[word[i]];
           }
            curr-> endOfWord =true;
        }
        // to handle repetitive words in result list
        unordered_set<string> track;


        // going to every cell 
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    dfs(i,j,board,root,"",result,track);  
                }
            }
        
        return result;
    }
};