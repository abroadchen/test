import java.security.KeyStoreException;

public class MinWindow {

    static String minWindow(String s, String t) {
        char[] target = t.toCharArray();
        int[] targetCount = new int[128];
        for (char ch: target) {
            targetCount[ch]++;
        }
        int passTotal = 0;
        for (int count: targetCount) {
            if (count > 0) {
                passTotal++;
            }
        }
        int passed = 0;
        char[] source = s.toCharArray();
        int[] sourceCount = new int[128];
        int i = 0;
        int j = 0;
        Result res = null;
        while (j < source.length) {
            char right = source[j];
            sourceCount[right]++;
            if (sourceCount[right] == targetCount[right]) {
                passed++;
            }
            while (passTotal == passed && i <= j) {
                if (res == null) {
                    res = new Result(i, j);
                } else {
                    if (j - i < res.j - res.i) {
                        res = new Result(i, j);
                    }
                }
                char left = source[i];
                sourceCount[left]--;
                if (sourceCount[left] < targetCount[left]) {
                    passed--;
                }
                i++;
            }
            j++;
        }
        return res == null ? "" : new String(source, res.i, res.j - res.i + 1);
    }

    static class Result {
        int i;
        int j;

        public Result(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
}
