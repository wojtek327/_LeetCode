int findClosestNumber(int* nums, int numsSize) {
    int retVal = nums[0];

    for(int i = 1; i<numsSize; i++) {
        if(abs(retVal) > abs(nums[i]))
        {
            retVal = nums[i];
        }
        else if((abs(retVal) == abs(nums[i])) && (nums[i] > retVal))
        {
            retVal = nums[i];
        }
    }

    return retVal;
}
