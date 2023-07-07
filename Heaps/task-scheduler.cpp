class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int>> queue;
        int time = 0;
        unordered_map<char,int> map;
        int len = tasks.size();

        for(int i=0;i<len;i++){
            map[tasks[i]]++;
        }

        for(auto i = map.begin();i!=map.end();i++){
            pq.push(i->second);
        }

        while(pq.empty()==false || queue.empty()==false){
            time++;

            if(pq.empty()==false){
            int element = pq.top();
            pq.pop();
                if(element-1!=0)
                queue.push(make_pair(element-1 ,time+n));
            }

            if(queue.empty()==false && queue.front().second == time ){
                int ele =queue.front().first;
                pq.push(ele);
                queue.pop();
            }
                        
        }

        return time;
    }
};