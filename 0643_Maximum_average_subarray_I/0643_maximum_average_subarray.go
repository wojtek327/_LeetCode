func findMaxAverage(nums []int, k int) float64 {
    curSum := 0.0

    // Calculate the first sum
    for i := 0; i < k; i++ {
        curSum += float64(nums[i])
    }

    maxAvg := curSum / float64(k)

    // Move and update if we find a larger average
    for i := k; i < len(nums); i++ {
        curSum += float64(nums[i]) - float64(nums[i-k])
        avg := curSum / float64(k)
        if avg > maxAvg {
            maxAvg = avg
        }
    }

    return maxAvg
}