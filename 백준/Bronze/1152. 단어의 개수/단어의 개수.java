import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String a = scn.nextLine();
        int count = 0;
        String[] arr=a.split("\\s");
        for (int i =0; i<arr.length; i++){
            count ++;
            //System.out.println(arr[i]);
        }
        for(int i = 0; i<arr.length; i++){
            if(Objects.equals(arr[i], "")){
                count--;
            }
        }
        System.out.println(count);
    }
}
