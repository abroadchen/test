public class MergeSortBottomUp {

    public static void sort(int[] a1) {
        int n = a1.length;
        int[] a2 = new int[n];
        for (int width = 1; width < n; width *= 2) {
            for (int left = 0; left < n; left += 2 * width) {
                int right = Math.min(left + 2 * width - 1, n - 1);
                int m = Math.min(left + width - 1, n - 1);
                merge(a1, left, m, m + 1, right, a2);
            }
            int[] temp = a1;
            a1 = a2;
            a2 = temp;
        }
    }
}
