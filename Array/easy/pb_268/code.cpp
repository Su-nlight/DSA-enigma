class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x1=0;
        for(int i=0; i<nums.size(); i++){
            x1=x1^nums[i]^(i+1);
        }
        return(x1);
    }
};