public class FractionalKnapsackProblem {

    static void select(Item[] items, int total) {
        Arrays.sort(items, Comparator.comparingInt(Item::unitValue).reversed());
        int max = 0;
        for (Item item: items) {
            if (total >= item.weight) {
                total -= item.weight;
                max += item.value;
            } else {
                max += total * item.unitValue();
                break;
            }
        }
    }





    static class Item {
        int index;
        int weight;
        int value;

        public Item(int index, int weight, int value) {
            this.index = index;
            this.weight = weight;
            this.value = value;
        }

        public int unitValue() {
            return value / weight;
        }

        @Override
        public String toString() {
            return "Item{" +
                    "index=" + index +
                    ", weight=" + weight +
                    ", value=" + value +
                    '}';
        }
    }
}
