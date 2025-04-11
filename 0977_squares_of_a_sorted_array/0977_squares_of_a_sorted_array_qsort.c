/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for(int i = 0; i<(numsSize); i++) {
        result[i] = nums[i] * nums[i];
    }

    qsort(result, numsSize, sizeof(int), compare);

    return result;
}
