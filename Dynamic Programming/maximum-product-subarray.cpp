class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dp(n);

        dp[0]=make_pair(nums[0],nums[0]);
        int m=nums[0];
        for(int i=1;i<n;i++){
            int f= dp[i-1].first*nums[i];
            int s= dp[i-1].second*nums[i];
            dp[i]= make_pair(max(max(nums[i],f),s),min(min(nums[i],f),s));
            if(dp[i].first>m){
                m=dp[i].first;
            }
        }

        return m;
    }
};