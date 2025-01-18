public class SelectionSort {

    public static void sort(int[] a) {
        for (int right = a.length - 1; right > 0; right--) {
            int max = right;
            for (int i = 1; i <= right; i++) {
                if (a[i] > a[max]) {
                    max = i;
                }
            }
            if (max != right) {
                swap(a, max, right);
            }
        }
    }

    private static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}
