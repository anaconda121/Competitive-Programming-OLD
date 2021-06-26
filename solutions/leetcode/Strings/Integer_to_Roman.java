//https://leetcode.com/problems/integer-to-roman
//treemap with possible combos
//while loop as long as number is not formed
import java.util.TreeMap;
import static java.util.Collections.reverseOrder;
import java.util.Collections;

public class Integer_to_Roman {
    public String intToRoman(int num) {
        TreeMap<Integer, String> conversion = new TreeMap<Integer, String>(Collections.reverseOrder());
        conversion.put(1, "I");
        conversion.put(4, "IV");
        conversion.put(5, "V");
        conversion.put(9, "IX");
        conversion.put(10, "X");
        conversion.put(40, "XL");
        conversion.put(50, "L");
        conversion.put(90, "XC");
        conversion.put(100, "C");
        conversion.put(400, "CD");
        conversion.put(500, "D");
        conversion.put(900, "CM");
        conversion.put(1000, "M");
        int currSum = num;
        String ans = "";
        while (currSum > 0) {
            for (Map.Entry<Integer, String> i : conversion.entrySet()){
                while (i.getKey() <= currSum) {
                    ans += "" + i.getValue();
                    currSum -= i.getKey();
                }
            }
        }
        return ans;
    }
}