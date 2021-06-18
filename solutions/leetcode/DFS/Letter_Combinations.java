//https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
//elegant brute force
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
public class Letter_Combinations {
    public static List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<String>();
        if (digits.equals("")) {
            return ans;
        }
        String[] allLetters = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        char[] nums = digits.toCharArray();
        //System.out.println(Arrays.toString(nums));
        String[] letters = new String[nums.length];
        for (int i = 0; i < letters.length; i++) {
            letters[i] = allLetters[Character.getNumericValue(nums[i])];
        }
        //System.out.println(Arrays.toString(letters));
        int one = 0;
        int two = 1;
        int three = 2;
        int four = 3;
        for (int i = 0; i < letters[0].length(); i++) {
            if (letters.length >= 2) {
                for (int j = 0; j < letters[1].length(); j++) {
                    if (letters.length >= 3) {
                        for (int k = 0; k < letters[2].length(); k++) {
                            if (letters.length == 4) {
                                for (int l = 0; l < letters[3].length(); l++) {
                                    if (letters.length == 4) {
                                        String next = letters[one].charAt(i) + "" + letters[two].charAt(j)  + "" + letters[three].charAt(k) + "" + letters[four].charAt(l);
                                        ans.add(next);
                                    }
                                }
                            }
                            if (letters.length == 3) {
                                String next = letters[one].charAt(i) + "" + letters[two].charAt(j)  + "" + letters[three].charAt(k);
                                ans.add(next);
                            }
                        }
                    }
                    //System.out.println(letters[one].charAt(i) + "" + letters[two].charAt(j));
                    if (letters.length == 2) {
                        String next = letters[one].charAt(i) + "" + letters[two].charAt(j);
                        ans.add(next);
                    }
                }
            }
            if (letters.length == 1) {
                String next = letters[one].charAt(i) + "";
                ans.add(next);
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        List<String> ret = letterCombinations("234");
        System.out.println(ret);
    }
}
