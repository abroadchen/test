public class l3 {

    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        int begin = 0;
        int maxLength = 0;
        for (int end = 0; end < s.length(); end++) {
            char ch = s.charAt(end);
            if (mao.containsKey(ch)) {
                begin = Math.max(map.get(ch) + 1, begin);
                map.put(ch, end);
            } else {
                map.put(ch, end);
            }
            maxLength = Math.max(maxLength, end - begin + 1);
        }
        return maxLength;
    }
}
