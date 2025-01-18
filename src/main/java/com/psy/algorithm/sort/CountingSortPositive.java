public class CountingSortPositive {

    public static void sort(int[] a) {
        int max = a[0];
        int min = a[0];
        for (int i = 1; i < a.length; i++) {
            if (a[i] > max) {
                max = a[i];
            }
            if (a[i] < min) {
                min = a[i];
            }
        }
        int[] count = new int[max - min + 1];
        for (int v: a) {
            count[v - min]++;
        }
        int k = 0;
        for (int i = 0; i < count.length; i++) {
            while (count[i] > 0) {
                a[k++] = i + min;
                count[i]--;
            }
        }
    }
}
