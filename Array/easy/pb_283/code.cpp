class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
        int j=-1,i;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i; break;
            }
        }
        if(nums.size()==0 or nums.size()==1 or j==-1) return;
        for(i=j+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i], nums[j]);
                j+=1;
            }
        }
    }
};