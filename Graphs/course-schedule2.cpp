class Solution {
public:
    bool dfs(int i,unordered_map<int,vector<int>> &map,unordered_set<int>&order, unordered_set<int>&visited,vector<int>&result){
        if(visited.find(i)!=visited.end()){
            return false;
        }

        if(map[i].size() ==0 && order.find(i)==order.end()){
            order.insert(i);
            result.push_back(i);
            return true;
        }

        if(map[i].size() ==0){
            return true;
        }
        visited.insert(i);
        int n= map[i].size();
        for(int j=0;j<n;j++){
            if(dfs(map[i][j],map,order,visited,result)==false){
                return false;
            }
        }

        visited.erase(i);
        map[i]={};
        result.push_back(i);
        order.insert(i);
        return true;


    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // similar to course schedule 1 but to avoid repetition of nodes in the result array, need another set 
        unordered_set<int> visited;
        unordered_set<int> order;
        unordered_map<int,vector<int>>map;
        vector<int> result;
        int n= prerequisites.size();

        for(int i=0;i<numCourses;i++){
            map[i]={};
        }

        for(int i=0;i<n;i++){
            int curr=prerequisites[i][0];
            int req = prerequisites[i][1];
            map[curr].push_back(req);
        }

        for(int i=0;i<numCourses;i++){
            if(dfs(i,map,order,visited,result)==false){
                vector<int> r;
                return r;
            }
        }

        return result;



    }
};