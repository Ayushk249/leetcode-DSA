// Caching the results of the recursive calls
class Solution {
public:
    int dfs(int i, int total,vector<int>& nums, int target,map<pair<int,int>,int>&m){
        if(i>=nums.size()){
            return (total == target) ? 1  :  0;
        }

        if(m.find(make_pair(i,total)) != m.end()){
            return m[make_pair(i,total)];
        }

        // recursive call
        m[make_pair(i,total)] = dfs(i+1,total+nums[i],nums,target,m) + dfs(i+1,total-nums[i],nums,target,m);
        return m[make_pair(i,total)];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // (index,total) --> no of ways
        map<pair<int,int>,int> m;

        return dfs(0,0,nums,target, m);
    }
};