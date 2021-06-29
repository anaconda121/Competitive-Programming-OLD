import java.util.Arrays;
public class Product_Array {
    public static int[] productExceptSelf(int[] nums) {
        int[] ans = new int[nums.length];
        int product = 1;
        for (int i = 0; i < nums.length; i++) {
            ans[i] = product * ans[i];
            product *= nums[i];
            System.out.println(Arrays.toString(ans));
        }
        ans[0] = product;
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = new int[] {1,2,3,4};
        System.out.println(productExceptSelf(arr));
    }
}
