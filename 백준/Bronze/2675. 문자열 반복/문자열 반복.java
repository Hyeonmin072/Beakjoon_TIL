import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int input = scn.nextInt();
        for (int i = 0;  i< input; i++){
            String[] arr;
            int count = scn.nextInt();
            String a = scn.next();
            arr=a.split("");
            for (int l=0; l<a.length(); l++){
                for(int j =0; j<count; j++){
                    System.out.print(arr[l]);
                }
            }
            System.out.println();
        }
        scn.close();
    }
}
