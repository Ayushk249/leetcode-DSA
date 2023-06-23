class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        int rob1=0;
        int rob2= 0;
        
        for(int i=0;i<n;i++){
            nums[i]= max(rob1+nums[i],rob2);
            int temp= rob2;
            rob2=nums[i];
            rob1=temp;
        }

        return nums[n-1];
    }
};