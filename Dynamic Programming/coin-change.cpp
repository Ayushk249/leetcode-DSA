class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        int n=coins.size();
        sort(coins.begin(),coins.end());

        dp[0]=0;
        for(int i=1;i<amount+1;i++){
            int j=0;
            while(j<n){
                if(i-coins[j]>=0){
                    dp[i] = min(dp[i],1+dp[i-coins[j]]);
                }
                j++;
            }
        }

        if(dp[amount]==amount+1){
            return -1;
        }
        return dp[amount] ;
    }
};