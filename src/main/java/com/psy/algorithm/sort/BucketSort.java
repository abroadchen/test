public class BucketSort {

    public static void sort(int[] ages) {
        DynamicArray[] buckets = new DynamicArray[10];
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new DynamicArray();
        }
        for (int age: ages) {
            buckets[age / 10].addLast(age);
        }
        int k = 0;
        for (DynamicArray bucket: buckets) {
            int[] array = buckets.array();
            InsertionSort.sort(array);
            for (int v: array) {
                ages[k++] = v;
            }
        }
    }
}
