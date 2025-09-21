class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, el = -1;
        for(int i=0; i<nums.size();i++){
            if(cnt == 0){
                cnt = 1; 
                el=nums[i];
            }
            else if (nums[i] == el) cnt+=1;
            else cnt-=1;
        }
        return el;
    }
};