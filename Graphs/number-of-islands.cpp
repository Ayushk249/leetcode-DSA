
class Solution {
public:
    
    void bfs(int i,int j,vector<vector<char>>& grid){

        queue<pair<int,int>>q;
        int r= grid.size();
        int c =grid[0].size();

        grid[i][j] ='0';
        q.push(make_pair(i,j));

        while(q.empty()==false){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            // all possible directions to look
            vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

            for(int k=0; k<4;k++){
                int dr=directions[k].first;
                int dc=directions[k].second;

                if((row+dr) < r && (row+dr)>=0 &&
                    (col+dc) < c && (col+dc)>=0 &&
                    grid[row+dr][col+dc]=='1'){

                        q.push(make_pair(row+dr,col+dc));
                        grid[row+dr][col+dc]='0';
                    }

            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {

    

        int r= grid.size();
        int c =grid[0].size();

        if(r==0 && c==0){
            return 0;
        }

        // for marking cells which are visited

        int numIslands =0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){

                if(grid[i][j]=='1'){
                    bfs(i,j,grid);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
};