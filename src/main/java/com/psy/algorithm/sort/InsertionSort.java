public class InsertionSort {


    public static void sort(int[] a) {
        for (int low = 1; low < a.length; low++) {
            int t = a[low];
            int i = low - 1;
            while (i >= 0 && t < a[i]) {
                a[i + 1] = a[i];
                i--;
            }
            if (i != low - 1) {
                a[i + 1] = t;
            }
        }
    }

}
