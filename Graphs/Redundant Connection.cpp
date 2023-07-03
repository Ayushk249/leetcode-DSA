// union-find method
class Solution {
public:
// find function of union-find to find root parent
    int find( int i,vector<int>& parent){
        int p = parent[i];
        while(parent[p]!=p){
            p= parent[p];
        }
        return p;
    }

    bool Union (int i,int j, vector<int> &parent,vector<int> &rank){

        // find if they are connected
        int parent1=find(i,parent);
        int parent2 = find(j,parent);

        cout<<parent1<<" "<<parent2<<endl;
        if(parent1 == parent2){
            return false;
        }

        if(rank[parent1]>=rank[parent2]){
            parent[parent2]=parent1;
            rank[parent1]+= rank[parent2];
        }else{
            parent[parent1]=parent2;
            rank[parent2]+= rank[parent1];
        }

        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int> rank;
        vector<int> parent;
        vector<int> result;
        for(int i=0;i<n+1;i++){
            parent.push_back(i);
            rank.push_back(1);
        }

        for(int i=0;i<n;i++){
            int n1 =edges[i][0];
            int n2 = edges[i][1];

            bool res = Union(n1,n2,parent,rank);
            // first edge trying to add loop to complete graph
            if(res== false){
                result= edges[i];
                return result;
            }
        }

         return result;

    }
};