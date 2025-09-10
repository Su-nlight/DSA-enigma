class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1=0;
        for(int i: nums){
            x1^=i;
        }
        return x1;
    }
};