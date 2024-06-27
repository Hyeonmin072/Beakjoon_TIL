class Solution {
    public int[] solution(long n) {
        int[] answer = new int[String.valueOf(n).length()];
        int count = 0;
        while(n>0){
            answer[count++]=(int)(n%10);
            n/=10;
        }
        
        return answer;
    }
}