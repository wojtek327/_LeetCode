double findMaxAverage(int* nums, int numsSize, int k) {
    double cur_sum = 0.0;
    for (int i = 0; i < k; i++) {
        cur_sum += nums[i];
    }

    double max_avg = cur_sum / k;

    for (int i = k; i < numsSize; i++) {
        cur_sum += nums[i] - nums[i - k];
        double avg = cur_sum / k;
        if (avg > max_avg) {
            max_avg = avg;
        }
    }

    return max_avg;
}
