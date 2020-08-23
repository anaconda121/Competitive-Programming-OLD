import java.util.Scanner;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class maths_NOTDONE {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String mathLine = sc.nextLine();
        int len = mathLine.length();
        int remove = 0;
        int[] numbers = new int[len];
        String[] deadarray = new String[len];
        for (int i = 0; i < mathLine.length(); i++) {
            String character = String.valueOf(mathLine.charAt(i));
            try {
                if (character.equals("+")) {
                    deadarray[i] = character;
                } else {
                    numbers[i] = Integer.parseInt(character);
                }
            } catch(IllegalArgumentException e) {
                continue;
            }
        }
        /*
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == remove && i < numbers.length){
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = 0;
            }   
        }*/

        
        System.out.println(Arrays.toString(numbers)); 
        System.out.println(Arrays.toString(deadarray)); 
    }

    public static String removeElement(int[] input, int remove) {
        for (int i = 0; i < input.length; i++) {
            if (input[i] == remove){
                input[i] = input[i + 1];
                input[i + 1] = 0;
            }   
        }
        return Arrays.toString(input);
    }
}