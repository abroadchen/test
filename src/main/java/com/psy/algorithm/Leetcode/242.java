public class l242 {

    public boolean isAnagram(String s, String t) {
        return Arrays.equals(getKey(s), getKey(t));
    }

    private int[] getKey(String s) {
        int[] array = new int[26];
        char[] chars = s.toCharArray();
        for (char c : chars) {
            array[c - 'a']++;
        }
        return array;
    }
}
