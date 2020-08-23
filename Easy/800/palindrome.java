/* check if a number is a palindrome */
class palindrome {
    public boolean isPalindrome(int x) {
        
        String word = Integer.toString(x);
        int palLen = word.length();
        String reverse = "";
        boolean pal = false;
        
        for(int i = palLen - 1; i >= 0; i--){
          reverse += word.charAt(i);
        }
        
        if (reverse.equals(word)) {
            pal = true;
        } else {
            pal = false;
        }
        
        return pal;
    }

    public static void main(String [] args){
        boolean ret = new palindrome().isPalindrome(121);
        System.out.println(ret);
    }
}

