import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scn = new Scanner(System.in);
        int[] arr = new int[6];
        int[] ans = {1,1,2,2,2,8};
        for (int i = 0; i<6; i++){
            int input = scn.nextInt();
            arr[i] = input;
        }
        for(int i =0; i<6; i++){
            System.out.print(ans[i]-arr[i]+" ");
        }

    }
}
