public class LCP {

    static String longestCommonPrefix(String[] strings) {
        char[] first = strings[0].toCharArray();
        for (int i = 0; i < first.length; i++) {
            char ch = first[i];
            for (int j = 0; j < strings.length; j++) {
                if (strings[j].length() == i || ch != strings[j].charAt(i)) {
                    return new String(first, 0, i);
                }
            }
        }
        return strings[0];
    }
}
