/*
ID: tanisht1
LANG: JAVA
PROG: friday
*/

import java.io.*;
import java.util.*;

class friday {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("friday.in"));
        PrintWriter out = new PrintWriter(new File("friday.out"));

        int timespan = in.nextInt();
        int dayNumber = 0;
        int[] dayCounts = {0, 0, 0, 0, 0, 0, 0};
        for (int day = 1, month = 1, year = 1900; year < 1900 + (timespan-1); day++) {
            if (day == 13) {
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                    dayNumber = calcDay(day, month, year, 31);
                } else {
                    dayNumber = calcDay(day, month, year, 30);
                }
                if (month == 2 && year % 4 == 0 || month == 2 && year % 10 == 0 && year % 400 == 0) {
                    dayNumber = calcDay(day, month, year, 29);
                } else {
                    dayNumber = calcDay(day, month, year, 28);
                }
                dayCounts[dayNumber]++;
                System.out.println(Arrays.toString(dayCounts));
            }
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 && day == 31) {
                month++;
                day = 1;
            } else if (month == 9 || month == 4 || month == 6 || month == 11 && day == 30) {
                month++;
                day = 1;
            }
            if (month == 12 && day == 31) {
                month = 1;
                day = 1;
                year++;
            }
        }
        for (int i = 0; i < dayCounts.length; i++) {
            out.print(dayCounts[i] + " ");
        }

        out.close();
    }

    public static int calcDay(int day, int month, int year, int totalDays) {
        double a = 0.0;
        int y = 0;
        int temp = 0;

        a = (month - 2 + 12) % 12;
        if (month <= 2) {
            year--;
        }

        y = 5 * (year % 4) + 4 *(year % 100) + 6 * (year % 400);
        temp = (day + (int)(2.6 * a - 0.2) + y) % 7;
        return temp;
    }
}