//https://leetcode.com/problems/continuous-subarray-sum/
public class Continous_Subarray_Sum {
    public boolean checkSubarraySum(int[] nums, int k) {
        if(nums.length == 1) {
            return false;
        }
        
        int [] left = new int [nums.length];
        left[0] = nums[0];

        for(int i = 1 ; i < nums.length; i++) {
            //0 universal multiple
            if(nums[i] == 0 && nums[i-1] == 0){
                return true;
            }
            left[i] = nums[i]+left[i-1];
            if(left[i] % k == 0) {
                return true;
            }
        }
        
        //whole arr sum is less than k, no hope
        if(k > left[nums.length-1]) {
            return false;
        }
        
        //searching all subsets now
        for(int i = 1 ; i < nums.length - 1 ; i++) {
            for(int j = i+1 ; j <= nums.length - 1 ; j++) {
                int rangeSum = left[j] - left[i-1];
                if(rangeSum % k == 0) {
                    return true;
                }
            }
        }
        return false;
    }
}
