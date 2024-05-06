//챗 gpt
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int answer = 0;

        while (true) {
            st = new StringTokenizer(br.readLine());
            answer = Integer.parseInt(st.nextToken());

            if (answer < 0)
                continue;
            if (answer < 100)
                break;
        }

        int trueAnswer = answer;
        int count = 1;

        while (true) {
            int left = answer / 10;
            int right = answer % 10;
            int sum = left + right;
            int sumRight = sum % 10;
            int result = right * 10 + sumRight;

            if (result == trueAnswer) {
                System.out.println(count);
                break;
            }

            answer = result;
            count++;
        }
    }
}

