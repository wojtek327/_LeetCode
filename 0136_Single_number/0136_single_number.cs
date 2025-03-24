
public class Solution {
    public int SingleNumber(int[] nums) {
        int element = nums[0];
        
        if(nums.Length == 1){
            return element;
        }
        
        for(int i = 1; i < nums.Length; i++){
            element ^= nums[i];
        }
        
        return element;
        
    }
}
