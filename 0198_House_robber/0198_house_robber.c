int rob(int* nums, int numsSize) {
    if(numsSize == 1) { return nums[0]; }
    else if(numsSize == 2) {
       return nums[0]>nums[1] ? nums[0] : nums[1];
    }

    int prev = nums[0];
    int curr = nums[0]>nums[1] ? nums[0] : nums[1];

    for(int i=2; i<numsSize; i++) {
        int temp = curr;
        curr = (nums[i] + prev) > curr ? nums[i] + prev : curr;
        prev = temp;
    }

    return curr;
}