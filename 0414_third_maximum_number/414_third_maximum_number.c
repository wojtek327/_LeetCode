int thirdMax(int* nums, int numsSize) {
    long big = LONG_MIN; //BIGGEST
    long mid = LONG_MIN; //SECOND BIGGEST
    long small = LONG_MIN; //THIRD BIGGEST

    if(numsSize == 1) { 
        return nums[0];
    }
    if(numsSize == 2) {
        if(nums[0] > nums[1]) { return nums[0]; }
        else { return nums[1]; }
    }

    for(uint16_t i=0; i<numsSize; i++) {
        if (nums[i] == big || nums[i] == mid || nums[i] == small) {
            continue;
        }

        if(nums[i] > big) {
            small = mid;
            mid = big;
            big = nums[i];
        } else if(nums[i] > mid) {
            small = mid;
            mid = nums[i];
        } else if(nums[i] > small) {
            small = nums[i];
        }
    }
    
    if(small != LONG_MIN) { return small; }
    else { return big; } 
}