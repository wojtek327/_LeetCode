int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize; 

    int leftProduct = 1;
    int rightProduct = 1;

    for (int i = 0; i < numsSize; i++) {
        ans[i] = leftProduct;
        leftProduct *= nums[i];
    }

    for (int i = numsSize - 1; i >= 0; i--) {
        ans[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return ans;
}