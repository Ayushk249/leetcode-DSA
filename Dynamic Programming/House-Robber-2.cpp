class Solution {
public:
    int rob(vector<int>& nums) {
        int one =0;
        int two=0;
        int three=0;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }

        for(int i=0;i<n-1;i++){
            three=max(one+nums[i],two);
            one=two;
            two=three;
        }

        int one2 =0;
        int two2=0;
        int three2=0;
        for(int i=1;i<n;i++){
            three2 = max(one2+nums[i],two2);
            one2 =two2;
            two2=three2;
        }

        return max(two,two2);
    }
};