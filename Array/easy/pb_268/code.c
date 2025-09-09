int missingNumber(int* nums, int numsSize) {
    int x1=0;
    for(int i=0;i<numsSize;i++)
        x1=x1^nums[i]^(i+1);
    return x1;
}