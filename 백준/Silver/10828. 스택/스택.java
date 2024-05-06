import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        ArrayList<Integer> list = new ArrayList<>();
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < n; i++) {
            String input = br.readLine();
            String[] parts = input.split(" ");
            String command = parts[0];

            switch (command) {
                case "push":
                    list.add(Integer.parseInt(parts[1]));
                    break;
                case "pop":
                    if (list.isEmpty()) {
                        result.append("-1\n");
                    } else {
                        result.append(list.remove(list.size() - 1)).append("\n");
                    }
                    break;
                case "size":
                    result.append(list.size()).append("\n");
                    break;
                case "empty":
                    result.append(list.isEmpty() ? "1\n" : "0\n");
                    break;
                case "top":
                    if (list.isEmpty()) {
                        result.append("-1\n");
                    } else {
                        result.append(list.get(list.size() - 1)).append("\n");
                    }
                    break;
            }
        }
        System.out.print(result.toString());
        br.close();
    }
}
