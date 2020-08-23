import java.util.Arrays;

class twoSum {
    public static int[] twoSum(int[] nums, int target) {
      int[] indexes = new int [2];

      for (int i = 0; i < nums.length; i++) {
        for (int j = i+1; j < nums.length; j++) {
            if (nums[i]+nums[j]==target) {
              if (i == j) {
                return new int[] {-1,-1};
              } else {
                return new int[] {i,j};   
              }
            }
        }
      }
      return new int[] {-1,-1};
      }
        
    public static void main(String[] args) {
        int[] nums = {2, 7, 7, 15};
        int[] indexes = twoSum(nums, 17);
       
        System.out.println(Arrays.toString(indexes));

    }
}