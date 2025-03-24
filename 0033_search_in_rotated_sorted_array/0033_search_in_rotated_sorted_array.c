int search(int* nums, int numsSize, int target) {
    int i = 0;
    int j = numsSize - 1;

    for(i = 0; i<(numsSize/2) + 1; i++) {
        if(nums[i] == target) {
            return i;
        } else if(nums[j] == target) {
            return j;
        }
        j--;
    }

    return -1;
}
