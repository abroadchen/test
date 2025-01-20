import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ThreadLocalRandom;

public class TinyURL {



    static class Codec {

        private static final char[] toBase62 = {};

        public static String toBase62(int number) {
            if (number == 0) {
                return String.valueOf(toBase62[0]);
            }
            StringBuilder sb = new StringBuilder();
            while (number > 0) {
                int r = number % 62;
                sb.append(toBase62[r]);
                number = number / 62;
            }
            return sb.toString();
        }


        private Map<String, String> longToShort = new HashMap<>();
        private Map<String, String> shortToLong = new HashMap<>();
        private static final String SHORT_PREFIX = "";
        private static int id = 1;//3

        public String encode(String longUrl) {
            String shortUrl = longToShort.get(longUrl);
            if (shortUrl != null) {
                return shortUrl;
            }
            shortUrl = SHORT_PREFIX + id;
            longToShort.put(longUrl, shortUrl);
            shortToLong.put(shortUrl, longUrl);
            id++;
            //int id = longUrl.hashCode();//2
            //while (true) {
            //    //int id = ThreadLocalRandom.current().nextInt();//1
            //    shortUrl = SHORT_PREFIX + id;
            //    if (!shortToLong.containsKey(shortUrl)) {
            //        longToShort.put(longUrl, shortUrl);
            //        shortToLong.put(shortUrl, longUrl);
            //        break;
            //    }
            //    id++;//2
            //}
            return shortUrl;
        }

        public String decode(String shortUrl) {
            return shortToLong.get(shortUrl);
        }
    }
}
