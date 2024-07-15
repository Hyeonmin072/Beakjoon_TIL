import java.util.Stack;
class Solution {
    boolean solution(String s) {
        Stack<Character> stk = new Stack<>();
        for(char c : s.toCharArray()){
            if(stk.isEmpty()){
                stk.push(c);
                continue;
            }
            
            if(stk.peek() == '(' && c==')')
                stk.pop();
            else
                stk.push(c);
        }
        return stk.isEmpty();
    }
}