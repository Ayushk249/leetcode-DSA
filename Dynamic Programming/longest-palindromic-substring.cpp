class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        string result;
        int max=INT_MIN;
        // odd palindromes
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;

            while(l>=0 && r<=n-1 && s[l]==s[r]){
                if(r-l+1 >max ){
                    max=r-l+1;
                    result = s.substr(l,max);
                }
                l--;
                r++;
            }
        }
        // even palindromes
        for(int i=0;i<n;i++){
            int l=i;
            int r=i+1;

            while(l>=0 && r<=n-1 && s[l]==s[r]){
                if(r-l+1 > max ){
                    max=r-l+1;
                    result = s.substr(l,max);
                }
                l--;
                r++;
            }
        }
        return result;
    }
};