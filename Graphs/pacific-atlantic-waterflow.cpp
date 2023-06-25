class Solution {
public:
// hash function for storing pairs in unordered sets
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
    void dfs (int i,int j,unordered_set<pair<int,int>,hash_pair> &s,int prevHeight,vector<vector<int>>& heights ){
       int rows = heights.size();
        int cols= heights[0].size();

        if(i>rows-1 || i<0 || j>cols-1 || j<0 || s.find(make_pair(i,j))!=s.end() || 
        heights[i][j] < prevHeight){
            return;
        }
        s.insert(make_pair(i,j));

        dfs(i+1,j,s,heights[i][j],heights);
        dfs(i-1,j,s,heights[i][j],heights);
        dfs(i,j+1,s,heights[i][j],heights);
        dfs(i,j-1,s,heights[i][j],heights);
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols= heights[0].size();

        // could be done using vector<vector<bool>> matrix to keep track of cells
        unordered_set<pair<int,int>,hash_pair> pacific;
        unordered_set<pair<int,int>,hash_pair> atlantic;
        vector<vector<int>> result;


        // starting from the borders of the ocean
        for(int c=0;c<cols;c++){
            dfs(0,c,pacific,heights[0][c],heights);
            dfs(rows-1,c,atlantic,heights[rows-1][c],heights);
        }

        for(int r=0;r<rows;r++){
            dfs(r,0,pacific,heights[r][0],heights);
            dfs(r,cols-1,atlantic,heights[r][cols-1],heights);
        }


        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(pacific.find(make_pair(r,c))!=pacific.end() && 
                    atlantic.find(make_pair(r,c))!=atlantic.end()){
                        vector<int>v = {r,c};
                        result.push_back(v);
                    }
            }
        }
        return result;
    }
};