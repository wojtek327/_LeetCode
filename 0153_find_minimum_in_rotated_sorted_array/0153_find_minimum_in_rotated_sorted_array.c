int findMin(int* nums, int numsSize) {
    int minVal = nums[0];

    for(uint16_t i=0, j = numsSize-1; i<(numsSize/2) + 1; i++) {
        if(minVal > nums[i]) {
            minVal = nums[i];
        }
        if(minVal > nums[j]) {
            minVal = nums[j];
        }
        j--;
    }

    return minVal;
}
