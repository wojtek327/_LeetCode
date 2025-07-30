//2 pointers
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    int left = 0;
    int right = numbersSize - 1;

    while(left < right) {
        int sum = numbers[left] + numbers[right];

        if(sum == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        }

        if(sum > target) {
            right--;
        } else {
            left++;
        }
    }

    return result;
}
