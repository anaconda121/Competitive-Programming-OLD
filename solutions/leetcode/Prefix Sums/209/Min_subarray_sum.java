//https://leetcode.com/problems/minimum-size-subarray-sum/submissions/
//make psums
// 2 pointers, if curr sum < target, l++ else r++
import java.util.Arrays;
public class Min_subarray_sum {
    public static int minSubArrayLen(int target, int[] nums) {
        int minLen = Integer.MAX_VALUE;
        int[] psums = new int[nums.length + 1];
        for (int i = 1 ; i <= nums.length; i++) {
            psums[i] = psums[i-1] + nums[i-1];
        }
        System.out.println(Arrays.toString(psums));
        int l = 0; int r = 1;
        while ((l < psums.length && r < psums.length) && l <= r) {
            int currSum = psums[r] - psums[l];
            System.out.println("L: " + l + " , R: " + r + ", CS: " + currSum);
            if (currSum >= target) {
                minLen = Math.min(minLen, r - l);
                l++;
                System.out.println("MinLen Changed: " + minLen + " : " + l + " : " + r);
            } else if (currSum < target) {
                r++;
            }
        }
        if (minLen == Integer.MAX_VALUE){
            return 0;
        }
        return minLen;
    }

    public static void main(String[] args) {
        int[] arr = new int[]{1,1,1,1,1,1,1,1,1,1,1,1,1};
        System.out.println(minSubArrayLen(11, arr));
    }
}
