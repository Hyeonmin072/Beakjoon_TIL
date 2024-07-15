import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int input = scan.nextInt();
        Stack<Character> stk = new Stack<>();

        for(int i=0; i<input; i++){
            stk.clear();
            String bracket = scan.next();
            for(int l =0; l<bracket.length(); l++){
                char c = bracket.charAt(l);
                if(stk.isEmpty()){
                    stk.push(c);
                    continue;
                }
                if(stk.peek() == '(' && c == ')') {
                    stk.pop();
                }
                else {
                    stk.push(c);
                }
            }

            if(stk.isEmpty()){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }
    }
}