
class Solution {
public:
    int distance(int x1,int y1){
        return (pow(x1,2)+pow(y1,2));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;

    int n= points.size();
    for(int i=0;i<n;i++){
        int x1 = points[i][0];
        int y1 = points[i][1];

        int d= distance(x1,y1);

        pq.push(make_pair(d,points[i]));
        }

         vector<vector<int>> result;

         while(k>0){
             result.push_back(pq.top().second);
             pq.pop();
             k--;
         }

        return result;
    }
};