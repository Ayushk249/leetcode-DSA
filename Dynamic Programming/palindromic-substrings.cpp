
class Solution {
public:
    int countSubstrings(string s) {
        int result=0;
        int n= s.size();

        for(int i=0;i<n;i++){
            int l=i;
            int r=i;

            while(l>=0 && r<=n-1 && s[l]==s[r]){
                result++;
                l--;
                r++;
            }

        }
        for(int i=0;i<n;i++){
            int l=i;
            int r=i+1;

            while(l>=0 && r<=n-1 && s[l]==s[r]){
                result++;
                l--;
                r++;
            }
        }
        return result;
    }
};