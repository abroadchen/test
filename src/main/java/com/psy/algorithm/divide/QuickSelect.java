public class QuickSelect {

    static int quick(int[] array, int left, int right, int i) {
        int p = partition(array, left, right);
        if (p == i) {
            return array[p];
        }
        if (i < p) {
            return quick(array, left, p - 1, i);
        } else {
            return quick(array, p + 1, right, i);
        }
    }

    static int partition(int[] a, int left, int right) {
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
}
