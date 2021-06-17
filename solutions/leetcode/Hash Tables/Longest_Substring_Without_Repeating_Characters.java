//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
//use arraylist to keep track of current set of nonrepeating letters
//if repeat, reset i back to the startidx of the sequence
import java.util.ArrayList;
public class Longest_Substring_Without_Repeating_Characters {
    public static int lengthOfLongestSubstring(String s) {
        char[] letters = s.toCharArray();
        ArrayList<Character> unique = new ArrayList<Character>();
        int maxLen = -1;
        boolean repeat = false;
        int startIdx = 0;
        for (int i = 0; i < letters.length; i++) {
            // if(repeat){
            //     i -= 1;
            //     repeat = false;
            // }
            //System.out.println("i: " + i);
            if (!unique.contains(letters[i])){
                if (unique.size() == 0) {
                    startIdx = i;
                }
                unique.add(letters[i]);
            } else {
                maxLen = Math.max(maxLen, unique.size());
                unique.clear();
                System.out.println(startIdx);
                i = startIdx;
                //repeat = true;
            }
            //System.out.println(unique);
        }
        return Math.max(maxLen,unique.size());
    }

    public static void main(String[] args) {
        int ans = lengthOfLongestSubstring("pppefg");
        System.out.print(ans);
    }
}