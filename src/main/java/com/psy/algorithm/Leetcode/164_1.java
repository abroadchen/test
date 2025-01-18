public class l164 {

    public int maximumGap(int[] nums) {
        if (nums.length < 2) {
            return 0;
        }
        int max = nums[0];
        int min = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        int range = Math.max((max - min) / nums.length, 1);
        Pair[] buckets = new Pair[(max - min) / range + 1];
        for (int v: nums) {
            int idx = (v - min) / range;
            if (buckets[idx] == null) {
                buckets[idx] = new Pair();
            }
            buckets[(v - min) / range].add(v);
        }
        int r = 0;
        int lastMax = buckets[0].max;
        for (int i = 1; i < buckets.length; i++) {
            Pair bucket = buckets[i];
            if (bucket != null) {
                r = Math.max(r, bucket.min - lastMax);
                lastMax = bucket.max;
            }
        }
        return r;
    }

    static class Pair {
        int max = 0;
        int min = 1000000000;

        void add(int v) {
            max = Math.max(max, v);
            min = Math.min(min, v);
        }

        @Override
        public String toString() {
            return "[" + "max=" + max + ", min=" + min + "]";
        }
    }
}
