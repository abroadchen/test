public class l1636 {


    public int[] frequencySort(int[] nums) {
        int[] freq = new int[201];
        for (int num : nums) {
            freq[num + 100]++;
        }
        int[] sorted = new int[nums.length];
        int index = 0;
        for (int i = 0; i < freq.length; i++) {
            for (int j = 0; j < freq[i]; j++) {
                sorted[index++] = i - 100;
            }
        }
        
        Arrays.stream(nums).boxed().sorted((a, b) -> {
            int af = count[a + 100];
            int bf = count[b + 100];
            if (af < bf) {
                return -1;
            } else if (af > bf) {
                return 1;
            } else {
                return b - a;
            }
        }).mapToInt(Integer::intValue).toArray();

        return sorted;
    }
}
