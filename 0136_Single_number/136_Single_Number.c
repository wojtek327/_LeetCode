//XOR
int singleNumber(int* nums, int numsSize) {
    int ans = 0;
    for (uint16_t i = 0; i < numsSize; i++) {
        ans ^= nums[i];
    }
    return ans;
}