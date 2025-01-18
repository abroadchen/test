public class RadixSort {


    public static void radixSort(String[] a, int length) {
        ArrayList<String>[] buckets = new ArrayList[128];
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new ArrayList<>();
        }
        for (int i = length - 1; i >= 0; i--) {
            for (String s: a) {
                buckets[s.charAt(i)].add(s);
            }
            int k = 0;
            for (ArrayList<String> bucket: buckets) {
                for (String s: bucket) {
                    a[k++] = s;
                }
                bucket.clear();
            }
        }
    }
}
