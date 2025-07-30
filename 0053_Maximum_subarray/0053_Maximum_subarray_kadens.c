int maxSubArray(int* nums, int numsSize) {
    int res = nums[0];
    int maxEnding = nums[0];

    for (int i = 1; i<numsSize; i++) {
        maxEnding = (maxEnding + nums[i] > nums[i]) ? maxEnding + nums[i] : nums[i];
        res = (res > maxEnding) ? res : maxEnding;
    }
    return res;
}
