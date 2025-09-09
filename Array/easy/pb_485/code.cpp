class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_cnt = 0;
        for(int count=0,i=0;i<nums.size();i++){
            if(nums[i]==1) {
                count+=1;
                if(max_cnt<count) max_cnt=count;
                }
            else count=0;
        } 
        return max_cnt;
    }
};