import java.util.*;

public class question1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] nums = new int[7];
        for (int i = 0; i < 7; i++) {
            nums[i] = in.nextInt();
        }
        Arrays.sort(nums);
        System.out.println(nums[0] + " " + nums[1] + " " + (nums[6]-nums[1]-nums[0]));
        in.close();
    }
}