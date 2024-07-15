import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        Queue<Integer> queue = new LinkedList<>();
        int answer = 0;

        // 로케이션에 해당하는 값을 음수로 바꿈
        priorities[location] *= -1;

        // 큐에 우선순위 넣기
        for (int priority : priorities) {
            queue.offer(priority);
        }

        while (!queue.isEmpty()) {
            int current = queue.poll();
            boolean isMax = true;

            // 절대값으로 우선순위 비교
            for (int value : queue) {
                if (Math.abs(current) < Math.abs(value)) {
                    isMax = false;
                    break;
                }
            }

            if (isMax) {
                answer++;
                if (current < 0) {  // 음수면 찾던 프로세스
                    return answer;
                }
            } else {
                queue.offer(current);
            }
        }

        return answer;
    }
}