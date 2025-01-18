public class QuickSortHoare {

    public static void sort(int[] a) {
        quick(a, 0, a.length - 1);
    }

    private static void quick(int[] a, int left, int right) {
        if (left >= right) {
            return;
        }
        int p = partition(a, left, right);
        quick(a, left, p - 1);
        quick(a, p + 1, right);
    }

    private static int partition(int[] a, int left, int right) {
        int idx = ThreadLocalRandom.current().nextInt(right - left + 1) + left;
        swap(a, left, idx);
        int pivot = a[left];
        int i = left, j = right;
        while (i < j) {
            while (i < j && a[j] > pivot) {
                j--;
            }
            while (i < j && a[i] <= pivot) {
                i++;
            }
            swap(a, i, j);
        }
        swap(a, left, i);
        return i;
    }

    private static void swap(int[] a, int i, int j) {
        if (i != j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}
