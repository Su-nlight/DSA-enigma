class Solution {
public:
    bool check(vector<int>& nums) {
        int len=nums.size();
        if(len==0||len==1) return true;
        int flag = 0;
        for(int i=0;i<len;i++){
            if(nums[i] > nums[(i+1)%len]) flag++;
            if(flag>1) return false;
        }
        return true;
    }
};