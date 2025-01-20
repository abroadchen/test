public class LongestSubstring {

    static int longestSubstring(String s, int k) {
        if (s.length() < k) {
            return 0;
        }
        int[] counts = new int[26];
        char[] chars = s.toCharArray();
        for (char c: chars) {
            counts[c - 'a']++;
        }
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            int count = counts[c - 'a'];
            if (count > 0 && count < k) {
                int j = i + 1;
                while (j < s.length() && counts[chars[j] - 'a'] < k) {
                    j++;
                }
                return Integer.max(longestSubstring(s.substring(0, i), k), longestSubstring(s.substring(j), k));
            }
        }
        return s.length();
    }
}
