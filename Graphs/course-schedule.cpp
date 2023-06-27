class Solution {
public:
    bool dfs(int i,unordered_set <int>& visited,unordered_map<int,vector<int>> &map){
        if(visited.find(i)!=visited.end()){
            return false;
        }

        if(map[i].size() == 0){
            return true;
        }

        visited.insert(i);
        int n= map[i].size();
        for(int j=0;j<n;j++){
            if(dfs(map[i][j],visited,map)==false){
                return false;
            }
        }
        // we are not visiting the cell
        visited.erase(i);
        // to avoid repeated work
        map[i]={};
        return true;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n= prerequisites.size();

        unordered_map<int,vector<int>> map;
        unordered_set <int> visited;
        for(int i=0;i<numCourses;i++){
            map[i]={};
        }
        for(int i=0;i<n;i++){
            int curr = prerequisites[i][0];
            int req = prerequisites[i][1];
            map[curr].push_back(req);
        }

        for(int i=0;i<numCourses;i++){
            if(dfs(i,visited,map)==false){
                return false;
            }
        }

        return true;

    }
};