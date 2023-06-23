// value of the current element depends only on previous two values

class Solution {
public:
    int climbStairs(int n) {
        int one= 1;
        int two= 1;

        for(int i=1;i<n;i++){
            int temp= one;
            one = one+two;
            two=temp;
        }

        return one;
    }
};