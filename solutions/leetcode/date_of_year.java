import java.util.*;
import java.io.*;
public class date_of_year {
    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(System.in);
        int[] leap = {31,29,31,30,31,30,31,31,30,31,30,31};
        int[] non_leap = {31,28,31,30,31,30,31,31,30,31,30,31};
        String date = in.nextLine();
        String[] parts = date.split("-");
        int month = Integer.parseInt(parts[1]);
        int day = Integer.parseInt(parts[2]);
        int year = Integer.parseInt(parts[0]);
        int days = 0;
        if (year % 4 ==0 && year % 100 != 0 || year % 4 ==0 && year % 400 == 0) {
            //leap year
            days = calcDays(leap, month, day);
        } else {
            days = calcDays(non_leap, month, day);
        }
        System.out.println(days);
    }

    public static int calcDays(int[] arr, int month, int day) {
        if (month == 1) {
            return day;
        }
        int days = 0;
        for (int i = 0; i < month-1; i++) {
            days += arr[i];
        }
        days += day;
        return days;
    }
}