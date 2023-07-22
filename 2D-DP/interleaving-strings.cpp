// caching solution
// class Solution {
// public:
//     bool dfs(int i1,int i2,string s1, string s2, string s3,map<pair<int,int>,bool>&m){
        
//             if(i1>=s1.size() && i2>=s2.size() && i1+i2>=s3.size()){
//                 return true;
//             }

//             if(m.find(make_pair(i1,i2)) != m.end()){
//                 return  m[make_pair(i1,i2)];
//             }


//             if(i1<s1.size() && s1[i1]== s3[i1+i2] &&  dfs(i1+1,i2,s1,s2,s3,m)){
//                 m[make_pair(i1,i2)] = true;
//                 return m[make_pair(i1,i2)];
//             } 
//             if(i2<s2.size() && s2[i2]== s3[i1+i2] && dfs(i1,i2+1,s1,s2,s3,m)){
//                  m[make_pair(i1,i2)] = true;
//                  return m[make_pair(i1,i2)];
//             }

//             m[make_pair(i1,i2)] = false;

//             return m[make_pair(i1,i2)];

            
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         // dictionary of (i1,i2) ---> whether we could form remaining of s3 from this point
//         map<pair<int,int>,bool> m;
//         return dfs(0,0,s1,s2,s3,m);

//     }
// };



// using DP array

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n= s1.size();
        int m = s2.size();

        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        if(s3.size()!= s1.size()+s2.size()){
            return false;
        }

        // base case of dp
        dp[n][m] = true;

        for(int i= n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i< s1.size() && s1[i]== s3[i+j] && dp[i+1][j]){
                    dp[i][j] =true;
                }
                if(j< s2.size() && s2[j]== s3[i+j] && dp[i][j+1]){
                    dp[i][j] =true;
                }

            }
        }

        return dp[0][0];


    }
};