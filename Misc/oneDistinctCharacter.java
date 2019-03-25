import java.util.*;

class oneDistinctCharacter {
    public static void main(String a[]) {
        System.out.println(substrings("anaveshahegghydxdtbbbbgfg", 4));
    }

    public static List<String> substrings(String s, int k) {
        Set<String> ans = new HashSet<String>();
        int length = s.length();
        for (int i = 0; i < length; i++) {
            String a = "";
            HashMap<Character, Boolean> check_char = new HashMap<Character, Boolean>();
            int dist_count = 0;
            if (i + k <= length) {
                for (int j = i; j < i + k; j++) {
                    if (check_char.containsKey(s.charAt(j))) {
                        dist_count++;
                    } else {
                        check_char.put(s.charAt(j), true);
                    }
                    a = a + s.charAt(j);
                }
            }

            if (dist_count == 1) {
                ans.add(a);
            }
        }
        return new ArrayList<String>(ans);
    }
}