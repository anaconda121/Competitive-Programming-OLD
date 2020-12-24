package silver.dec_2016;

import java.io.*;
import java.util.*;

public class citystate {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("citystate.in"));    
        PrintWriter out = new PrintWriter(new File("citystate.out"));
        //input
        int N = Integer.parseInt(in.nextLine());
        String[] cities = new String[N];
        String[] states = new String[N];
        String[] abbreviations = new String[N];
        HashMap<String,String> cs = new HashMap<String,String>();
        for (int i = 0; i < N; i++) {
            String curr = in.nextLine();
            String[] cityState = curr.split(" ");
            cities[i] = cityState[0];
            states[i] = cityState[1];
            char one = cities[i].charAt(0);
            char two = cities[i].charAt(1);
            abbreviations[i] = Character.toString(one) + Character.toString(two);
            cs.put(abbreviations[i],states[i]);
        }
        //System.out.println(cs);
        //logic
        int pair = 0;
        for (int i = 0; i < cs.size(); i++) {
            List keys = new ArrayList(cs.keySet());
            String currKey = (String) keys.get(i);
            for (int j = 0; j < cs.size(); j++) {
                String key =(String) cs.keySet().toArray()[j];
                String val = cs.get(key);
                if (currKey.equals(val)) {
                    int indx = j;
                    String valueAtI = cs.get(currKey);
                    if (key.equals(valueAtI)) {
                        pair++;
                    }
                }
            }
        }
        out.println(pair/2);

        out.close();
    }
}