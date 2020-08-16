import java.util.HashMap;
import java.util.Map;

class romanToInt {
    public static int romanToInt(String s) {
      Map <Character, Integer> map = new HashMap();
      map.put('I', 1);
      map.put('V', 5);
      map.put('X', 10);
      map.put('L', 50);     
      map.put('C', 100);     
      map.put('D', 500);
      map.put('M', 1000);
      
      int[] result = new int[s.length()];
      for (int i = 0; i < s.length(); i++) {
          if (i > 0 && map.get(s.charAt(i)) > map.get(s.charAt(i-1))) {
            //remove previous nums
            result[i - 1] = 0;
            result[i] += map.get(s.charAt(i)) - map.get(s.charAt(i - 1));
          } else {
              result[i] += map.get(s.charAt(i));
          }
      }
      
      int num = 0;
      for (int i = 0; i < result.length; i++) {
        num += result[i];
      }

      return num;
    }
                                  
    public static void main(String [] args) {
        int number = romanToInt("MCMXCIV");
        System.out.println(number);
    }
                        
}