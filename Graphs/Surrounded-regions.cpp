
class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>>&visited,vector<vector<char>>& board){
        int rows = board.size();
        int cols = board[0].size();
        if(i>rows-1 || i<0 || j>cols-1 || j<0  || visited[i][j]  || board[i][j]!='O'){
            return;
        }

        visited[i][j] =true;

        dfs(i+1,j,visited,board);
        dfs(i-1,j,visited,board);
        dfs(i,j+1,visited,board);
        dfs(i,j-1,visited,board);

    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));

        for(int r=0;r<rows;r++){
            dfs(r,0,visited,board);
            dfs(r,cols-1,visited,board);
        }
        for(int c=0;c<cols;c++){
            dfs(0,c,visited,board);
            dfs(rows-1,c,visited,board);
        }

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(board[r][c]=='O' && visited[r][c]==false){
                    board[r][c]='X';
                }
            }
        }
    }
};