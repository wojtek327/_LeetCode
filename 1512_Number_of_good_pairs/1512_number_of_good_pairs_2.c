//O(n)
//1 <= nums.length <= 100
//1 <= nums[i] <= 100
int numIdenticalPairs(int* nums, int numsSize){
    int numberOfGoodPairs = 0;
    int* hashMap = (int*)calloc(101, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        numberOfGoodPairs += hashMap[nums[i]];
        hashMap[nums[i]]++;
    }

    free(hashMap);
    return numberOfGoodPairs;
}
