//https://leetcode.com/problems/find-pivot-index/
// first do psums
// then calc pivot indexes as counter goes from 1 - psums.length - 2
// find leftmost and return
// p standard
public class Pivot_index {
    public int pivotIndex(int[] nums) {
        int[] psums = new int[nums.length + 1];
        for (int i = 1; i <= nums.length; i++) {
            psums[i] = psums[i - 1] + nums[i - 1];
        }
        int counter = 1;
        int s = 0;
        int e = psums.length - 1;
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < psums.length - 1; i++) {
            int l = psums[counter - 1] - psums[s];
            int r = psums[e] - psums[counter];
            //System.out.println("L: " + l + " , R: " + r);
            if (l == r) {
                if (ans == Integer.MIN_VALUE) {
                    ans = counter;
                } else {
                    ans = Math.min(ans, counter);
                }
            }
            counter++;
        }
        if (ans == Integer.MIN_VALUE) {
            return -1;
        }
        return ans - 1;
    }
    public static void main(String[] args) {
        int [] arr = new int[] {1,2,3};
        System.out.println(pivotIndex(arr));
    }
}
