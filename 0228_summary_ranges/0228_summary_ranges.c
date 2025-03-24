char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** ans = (char**)malloc(numsSize * sizeof(char*));
    *returnSize=0;

    for(int i=0; i<numsSize;) {
        int startVal = nums[i];

        while(i<(numsSize - 1) && nums[i + 1] == nums[i]+1) {
            i++;
        }

        ans[*returnSize] = (char*)malloc(25 * sizeof(char));

        if (startVal != nums[i])
        {
            sprintf(ans[*returnSize], "%d->%d", startVal,nums[i]);
        }
        else {
            sprintf(ans[*returnSize], "%d", startVal,nums[i]);
        }
        (*returnSize)++;
        i++;
    }
    return ans;
}
