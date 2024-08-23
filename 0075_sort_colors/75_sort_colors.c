void sortColors(int* nums, int numsSize) {
    uint16_t red = 0;
    uint16_t white = 0;
    uint16_t blue = 0;

    for(uint16_t i = 0; i<numsSize; i++)
    {
        if(nums[i] == 0) { red++; }
        else if(nums[i] == 1) { white++; }
        else { blue++; }
    }

    uint16_t j = 0;

    while(red != 0) {
        nums[j] = 0;
        red--;
        j++;
    }
    while(white != 0) {
        nums[j] = 1;
        white--;
        j++;
    }
    while(blue != 0) {
        nums[j] = 2;
        blue--;
        j++;
    }
}
