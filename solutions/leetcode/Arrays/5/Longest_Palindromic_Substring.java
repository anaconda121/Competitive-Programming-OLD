public class Longest_Palindromic_Substring {
    public static String longestPalindrome(String s) {
        String ans = "";
        int maxLen = -1;
        for (int i = 0; i < s.length(); i++){
            String curr = "" + s.charAt(i);
            for (int j = i; j < s.length(); j++) {
                if (i != j) {
                    curr += "" + s.charAt(j);
                }
                if (curr.charAt(0) == curr.charAt(curr.length()-1)) {   
                    StringBuilder input1 = new StringBuilder();
                    input1.append(curr);
                    input1.reverse();
                    String reverse = input1.toString();
                    if (curr.equals(reverse)) {
                        if (curr.length() > maxLen) {
                            maxLen = curr.length();
                            ans = curr;
                            //System.out.println(ans + " , " + i + " , " + j);
                        }
                    }
                }
                
                //System.out.println(curr);
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        String x= "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        
        System.out.println(x.length());
    }
}