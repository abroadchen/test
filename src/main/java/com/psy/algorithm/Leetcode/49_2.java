import java.util.HashMap;
import java.util.List;

public class l49_2 {

    static class ArrayKey {
        int[] key = new int[26];

        public ArrayKey(String str) {
            for (char c: str.toCharArray()) {
                key[c - 'a']++;
            }
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            ArrayKey arrayKey = (ArrayKey) o;
            return Arrays.equals(key, arrayKey.key);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(key);
        }
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<ArrayKey, List<String>> map = new HashMap<>();
        for (String str: strs) {
            ArrayKey key = new ArrayKey(str);
            List<String> list = map.computeIfAbsent(key, k -> new ArrayList<>());
            list.add(str);
        }
        return new ArrayList<>(map.values());
    }
}
