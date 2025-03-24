int firstMissingPositive(int* nums, int numsSize) {
    int nonPosIdx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 0) {
            int temp = nums[i];
            nums[i] = nums[nonPosIdx];
            nums[nonPosIdx] = temp;
            nonPosIdx++;
        }
    }

    for (int i = nonPosIdx; i < numsSize; i++) {
        int num = abs(nums[i]);
        if ((num <= (numsSize - nonPosIdx)) && nums[num - 1 + nonPosIdx] > 0) {
           nums[num - 1 + nonPosIdx] *= -1;
        }
    }

    for (int i = nonPosIdx; i < numsSize; i++) {
        if (nums[i] > 0) {
            return i - nonPosIdx + 1;
        }
    }

    return numsSize - nonPosIdx + 1;
}
