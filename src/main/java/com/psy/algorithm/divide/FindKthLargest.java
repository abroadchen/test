public class FindKthLargest {


    public int FindKthLargest(int[] a, int k) {
        return QuickSelect.quick(a, 0, a.length - 1, a.length - k);
    }
}
