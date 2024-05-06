import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int count = scan.nextInt();
        scan.nextLine(); // 개행문자 처리

        String[] word = new String[count];
        for (int i = 0; i < count; i++) {
            word[i] = scan.nextLine();
        }

        // 중복 제거
        Set<String> set = new HashSet<>(Arrays.asList(word));
        String[] arr = set.toArray(new String[0]);

        // 길이순으로 정렬
        Arrays.sort(arr, (a, b) -> {
            if (a.length() != b.length()) {
                return a.length() - b.length();
            } else {
                return a.compareTo(b);
            }
        });

        // 결과 출력
        for (String w : arr) {
            System.out.println(w);
        }
    }
}
