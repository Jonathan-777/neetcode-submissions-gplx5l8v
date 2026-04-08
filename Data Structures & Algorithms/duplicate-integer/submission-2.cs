public class Solution {
    public bool hasDuplicate(int[] nums) {
        Array.Sort(nums);
        int temp = int.MinValue;

        foreach (int x in nums){
            if(x == temp) return true;
            temp = x;
        }
        return false;
        
    }
}