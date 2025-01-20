public class ActivitySelectionProblem {

    public static void select(Activity[] activities, int n) {
        List<Activity> result = new ArrayList<>();
        Activity prev = activities[0];
        result.add(prev);
        for (int i = 1; i < n; i++) {
            Activity curr = activities[i];
            if (curr.start >= prev.finish) {
                result.add(curr);
                prev = curr;
            }
        }
    }




    static class Activity {
        int index;
        int start;
        int finish;

        public Activity(int index, int start, int finish) {
            this.index = index;
            this.start = start;
            this.finish = finish;
        }

        public int getFinish() {
            return finish;
        }

        @Override
        public String toString() {
            return "Activity{" +
                    "index=" + index +
                    ", start=" + start +
                    ", finish=" + finish +
                    '}';
        }
    }
}
