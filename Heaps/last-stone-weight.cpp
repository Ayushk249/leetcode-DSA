
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        int n= stones.size();
        for(int i=0;i<n;i++){
            q.push(stones[i]);
        }

        // taking first 2 stones of maxHeap
        while(q.size()>1){
            int stone1 = q.top();
            q.pop();
            int stone2 = q.top();
            q.pop();

            int res = max(stone1,stone2)- min(stone1,stone2);
            if(res>0){
                q.push(res);
            }

        }

        if(q.size()>0){
            return q.top();
        }

        return 0;
    }
};