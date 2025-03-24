//C#
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        if (nums == null || nums.Length == 0) { return 0; }

        int index = 1;

        for(int i = 1; i< nums.Length; i++)
        {
            if(nums[i] != nums[i - 1])
            {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
}
//C
int removeDuplicates(int* nums, int numsSize){

    if(numsSize == 0) { return 0; }

    int lastValidIndex = 1;

    for(int i = 1; i<numsSize; i++)
    {
        if(*(nums + i) != *(nums + i - 1))
        {
            *(nums + lastValidIndex) = *(nums + i);
            lastValidIndex++;
        }
    }
    return lastValidIndex;

}
//C 2
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) { return 0; }

    int uniqueIndex = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[uniqueIndex] = nums[i];
            uniqueIndex++;
        }
    }

    return uniqueIndex;
}
//C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) { return 0; }

        int lastValidIndex = 1;

        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i] != nums[i - 1])
            {
                nums[lastValidIndex] = nums[i];
                lastValidIndex++;
            }
        }
        return lastValidIndex;
    }
};
