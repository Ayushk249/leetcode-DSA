class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n);
        dp[0]=1;
        int max=1;
        for(int i=1;i<n;i++){
            int m=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && 1+dp[j] > m){
                    m=1+dp[j];
                }
            }

            if(max<m)
            max=m;
            dp[i]=m;
        }
        return max;
    }
};