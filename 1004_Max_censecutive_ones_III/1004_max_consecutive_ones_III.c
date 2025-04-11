int longestOnes(int* nums, int numsSize, int k) {
    int max_w = 0;
    int l = 0;
    int num_zeros = 0;
    for(int r = 0; r<numsSize; ++r) {
         if (nums[r] == 0) {
            num_zeros++;
        }

        while (num_zeros > k) {
            if (nums[l] == 0) {
                 num_zeros--;
             }
            l++;
        }

        if(max_w < r - l + 1) {
            max_w = r - l + 1;
        }
    }

    return max_w;
}
