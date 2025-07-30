
//Iteration TIME LIMIT EXCEEDED
int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];

    for(int i = 0; i<numsSize; i++) {
        int currSum = 0;

        for (int j = i; j < numsSize; j++) {
            currSum = currSum + nums[j];
          
            // Update maxSum if currSum is greater than maxSum
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
    }
    return maxSum;
}