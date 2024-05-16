import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String input = scn.next().toUpperCase();  // 대소문자 구분하지 않기 위해 모두 대문자로 변환
        scn.close();
        
        int[] frequency = new int[26];  // 알파벳 개수 (A-Z)
        
        // 빈도 계산
        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            frequency[ch - 'A']++;
        }
        
        // 최빈값 탐색
        int maxFreq = 0;
        char maxChar = '?';
        boolean isDuplicate = false;
        
        for (int i = 0; i < 26; i++) {
            if (frequency[i] > maxFreq) {
                maxFreq = frequency[i];
                maxChar = (char) (i + 'A');
                isDuplicate = false;
            } else if (frequency[i] == maxFreq) {
                isDuplicate = true;
            }
        }
        
        // 결과 출력
        if (isDuplicate) {
            System.out.println("?");
        } else {
            System.out.println(maxChar);
        }
    }
}
