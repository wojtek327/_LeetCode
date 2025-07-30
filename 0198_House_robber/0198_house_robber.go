
func max(num1, num2 int) int {
    if num1 > num2 {
        return num1
    }
    return num2
}

func rob(nums []int) int {
    n := len(nums)

    if n == 1 { 
        return nums[0]; 
    } else if n == 2 {
       return max(nums[0], nums[1])
    }

    prev := nums[0]
    curr := max(nums[0], nums[1])

    for i:=2; i<n; i++ {
        temp := curr
        curr = max((nums[i] + prev),curr)
        prev = temp
    }

    return curr;
}
