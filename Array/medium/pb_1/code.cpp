#include<unordered_map>
#include<iostream>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> din;
        vector<int> outp;
        for(int i=0;i<nums.size();i++){
            int comp=target-nums[i];
            if(din.count(comp)){
                return outp = {din[comp],i};
            }
            din[nums[i]]=i;
        }
        return outp = {};
    }
};