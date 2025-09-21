class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -10000, temp = 0;
        for(int i=0; i<nums.size(); i++){
            temp += nums[i];
            if (sum < temp) sum = temp;
            if (temp < 0) temp=0;
        }
        return sum;
    }
};