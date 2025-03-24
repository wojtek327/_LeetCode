int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = (numsSize - 1);

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target) {
            return mid;
        }

        if((nums[mid] > target)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
