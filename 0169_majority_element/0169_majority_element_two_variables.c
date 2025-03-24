int majorityElement(int* nums, int numsSize) {
    if(nums == NULL) { return 0; }
    if(*nums == '\0') { return 0; }

    int candidate = 0;
    int counter = 0;

    for (int i = 0; i < numsSize; i++) {
        if(counter == 0) {
            candidate = nums[i];
        }

        if(candidate == nums[i]) {
            counter += 1;
        }
        else {
            counter -= 1;
        }
    }

    return candidate;
}
