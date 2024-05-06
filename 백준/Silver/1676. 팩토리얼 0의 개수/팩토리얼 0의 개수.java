import java.util.Scanner;
import java.util.*;

public class Main {
    public static void main(String[] args) {

//        문제
//        N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.
//
//                입력
//        첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)
//
//        출력
//        첫째 줄에 구한 0의 개수를 출력한다.
        // 팩토리얼 3! == 3*2*1
        // 팩토리얼 5! == 5*4*3*2*1
        Scanner scan = new Scanner(System.in);
//        System.out.print("팩토리얼 : ");
//        int input = scan.nextInt();
//
//        int sum = 1;
//        for (int i = input; i>=1; i--){
//            sum *= i;
//        }
//        String result = Integer.toString(sum);
//        long[] dig = new long[result.length()];
//
//        for(int i = 0; i<result.length(); i++){
//            dig[i]= result.charAt(i)-'0';
//        }
//        int count =0;
//        for(int i = 0; i<result.length(); i++){
//            if(dig[i] ==0)
//                count++;
//        }
//        System.out.println(count);
////        리스트로 sum을 나누어 각각 한자리씩 받아 순회하여 0일때 result값 올리고 해당값 출력

        int n;
        int mul5;
        int mul25;
        int mul125;

        int input = scan.nextInt();

        mul5 = input/5;
        mul25 =input/25;
        mul125 = input/125;

        System.out.println(mul5+mul25+mul125);


    }
}

