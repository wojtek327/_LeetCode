inline int custom_abs(int n) {
    return (n < 0) ? -n : n;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    if(nums == NULL) { return result; }
    if(numsSize == 0) { return result; }

    int left = 0;
    int right = numsSize - 1;
    int pos = numsSize - 1;

    while (left <= right) {
        if (custom_abs(nums[left]) > custom_abs(nums[right])) {
            result[pos] = nums[left] * nums[left];
            left++;
        } else {
            result[pos] = nums[right] * nums[right];
            right--;
        }
        pos--;
    }

    return result;
}
