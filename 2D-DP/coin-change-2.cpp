// using dp array

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1));

        // rows --> coins denomination
        // columns --> amounts
        for(int i=0;i<n;i++){
            dp[i][0] =1;
        }

        for(int i=n-1;i>=0;i--){
            for(int j= 1;j<amount+1;j++){

            if(j-coins[i] >=0){
                if(i==n-1){
                     dp[i][j] = dp[i][j-coins[i]];
                }else{
                    dp[i][j] = dp[i][j-coins[i]] + dp[i+1][j];
                }     
            }

            if(j-coins[i] <0){
                if(i==n-1){
                     dp[i][j] = 0;
                    }else{
                    dp[i][j] = dp[i+1][j];
                    }
                }
            }
        }

        return dp[0][amount];
    }
};