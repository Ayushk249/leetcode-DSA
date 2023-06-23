class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.size();
        vector<bool> dp(n+1,false);
        int m= wordDict.size();
        dp[n] =true;

        // looping through characters
        for(int i=n-1;i>=0;i--){
            // looping in dict
            for(int j=0;j<m;j++){
                string str = wordDict[j];
                int l = str.size();
                if(n-i >= l){
                    string sub = s.substr(i,l);
                    if(sub==str){
                        dp[i]=dp[i+l];
                        if(dp[i]){
                            break;
                        }
                    }
                }
            }
        }
        return dp[0];
    }
};