import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scn = new Scanner(System.in);
        String input = scn.next();
        String arr[];
        arr = input.split("");
        int count = arr.length-1;
        String ans[] = new String[input.length()];
        for(int i = 0; i<arr.length; i++){
           // System.out.print(arr[i]);
            ans[i] = arr[count];
            count--;
        }
        String test1;
        //System.out.println();
        for(int i = 0; i<arr.length; i ++){
           // System.out.print(ans[i]);
        }
        //System.out.println();

        int check =arr.length;
        int stack =arr.length;
        //System.out.println("START STACK : "+stack);
        for(int i=0; i<arr.length; i++){
            if(Objects.equals(arr[i], ans[i]))
                stack--;
            else
                check=0;
            //System.out.println("STACK"+" "+stack);
        }
        if(check==0)
            System.out.print(check);
        else
            System.out.println(1);
    }
}
