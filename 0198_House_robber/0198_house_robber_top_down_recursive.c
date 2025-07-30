int robHelper(int* nums, int i, int* memo) {
    if (i < 0) return 0;       
    if (memo[i] >= 0) return memo[i]; 

    int result = 
        (robHelper(nums, i - 2, memo) + nums[i]) > (robHelper(nums, i - 1, memo))
        ? (robHelper(nums, i - 2, memo) + nums[i])
        : (robHelper(nums, i - 1, memo));
    
    memo[i] = result;
    return result;
}

int rob(int* nums, int numsSize) {
    int memo[numsSize];
    for (int i = 0; i < numsSize; i++) {
        memo[i] = -1;
    } // Inicjalizacja memo jako niezliczone (-1)

    return robHelper(nums, numsSize - 1, memo);
}